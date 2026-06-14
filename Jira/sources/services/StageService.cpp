#include "../../headers/services/StageService.h"

#include "../../headers/services/UserService.h"
#include "../../headers/services/ProjectService.h"
#include "../../headers/stages/StageValidator.h"
#include "../../headers/stages/Stage.h"
#include "../../headers/users/UserRole.hpp"
#include "../../headers/services/TaskService.h"

#include <stdexcept>

void StageService::addStage(Context& context, const std::string& projectName, const std::string& stageName, std::time_t startDate, std::time_t endDate) {
    requireTeachingAssistantOrLecturer(context);

    Project* project = ProjectService::findProjectByName(context, projectName);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    if (project->getStatus() == ProjectStatus::Finished) {
        throw std::runtime_error("Cannot add stage to finished project.");
    }

    StageValidator::validateName(stageName);
    StageValidator::validateDates(startDate, endDate);

    if (project->containsStage(stageName)) {
        throw std::invalid_argument("Stage already exists in this project.");
    }

    project->addStage(Stage(stageName, startDate, endDate));

    context.markChanged();
}

void StageService::startStage(Context& context, const std::string& projectName, const std::string& stageName) {
    requireTeachingAssistantOrLecturer(context);

    Project* project = ProjectService::findProjectByName(context, projectName);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    Stage* stage = project->getStageByName(stageName);

    if (stage == nullptr) {
        throw std::invalid_argument("Stage does not exist.");
    }

    if (project->getStatus() == ProjectStatus::Finished) {
        throw std::runtime_error("Cannot start stage in finished project.");
    }

    if (stage->getStatus() == StageStatus::Active) {
        throw std::runtime_error("Stage is already active.");
    }

    if (stage->getStatus() == StageStatus::Finished) {
        throw std::runtime_error("Finished stage cannot be started again.");
    }

    stage->start();
    context.markChanged();
}

void StageService::finishStage(Context& context, const std::string& projectName, const std::string& stageName) {
    requireTeachingAssistantOrLecturer(context);

    Project* project = ProjectService::findProjectByName(context, projectName);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    Stage* stage = project->getStageByName(stageName);

    if (stage == nullptr) {
        throw std::invalid_argument("Stage does not exist.");
    }

    if (project->getStatus() == ProjectStatus::Finished) {
        throw std::runtime_error("Cannot finish stage in finished project.");
    }

    if (stage->getStatus() == StageStatus::Finished) {
        throw std::runtime_error("Stage is already finished.");
    }

    if (stage->getStatus() == StageStatus::Planned) {
        throw std::runtime_error("Cannot finish stage that has not been started.");
    }

    stage->finish();
    context.markChanged();
}

void StageService::requireTeachingAssistantOrLecturer(Context& context) {
    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr) {
        throw std::runtime_error("No logged user.");
    }

    UserRole role = currentUser->getRole();

    if (role != UserRole::TeachingAssistant && role != UserRole::Lecturer) {
        throw std::runtime_error("Only teaching assistant or lecturer can manage stages.");
    }
}

void StageService::moveTaskToStage(Context& context, unsigned int taskId, const std::string& stageName) {
    requireTeachingAssistantOrLecturer(context);

    Task* task = TaskService::findTaskById(context, taskId);

    if (task == nullptr) {
        throw std::invalid_argument("Task does not exist.");
    }

    Project* project = ProjectService::findProjectByTaskId(context, taskId);

    if (project == nullptr) {
        throw std::runtime_error("Task is not connected to any project.");
    }

    if (project->getStatus() == ProjectStatus::Finished) {
        throw std::runtime_error("Cannot move task in finished project.");
    }

    Stage* targetStage = project->getStageByName(stageName);

    if (targetStage == nullptr) {
        throw std::invalid_argument("Stage does not exist.");
    }

    if (targetStage->getStatus() == StageStatus::Finished) {
        throw std::runtime_error("Cannot move task to finished stage.");
    }

    if (targetStage->containsTask(taskId)) {
        throw std::runtime_error("Task is already in this stage.");
    }

    for (Stage& stage : const_cast<std::vector<Stage>&>(project->getStages())) {
        stage.removeTask(taskId);
    }

    targetStage->addTask(taskId);

    context.markChanged();
}