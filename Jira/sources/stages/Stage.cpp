#include "../../headers/stages/Stage.h"
#include <algorithm>

std::string stageStatusToString(StageStatus status) {
    switch (status) {
    case StageStatus::Planned:
        return "Planned";
    case StageStatus::Active:
        return "Active";
    case StageStatus::Finished:
        return "Finished";
    default:
        return "Unknown";
    }
}

StageStatus stringToStageStatus(const std::string& str) {
    if (str == "Planned") {
        return StageStatus::Planned;
    }
    else if (str == "Active") {
        return StageStatus::Active;
    }
    else if (str == "Finished") {
        return StageStatus::Finished;
    }

    throw std::invalid_argument("Invalid stage status.");
}

Stage::Stage(const std::string& name, std::time_t startDate, std::time_t endDate)
    : name(name), startDate(startDate), endDate(endDate), status(StageStatus::Planned) {
}

Stage::Stage(const std::string& name, std::time_t startDate, std::time_t endDate, StageStatus status, const std::vector<unsigned int>& taskIds)
    : name(name), startDate(startDate), endDate(endDate), taskIds(taskIds), status(status) {
}

const std::string& Stage::getName() const {
    return name;
}

std::time_t Stage::getStartDate() const {
    return startDate;
}

std::time_t Stage::getEndDate() const {
    return endDate;
}

StageStatus Stage::getStatus() const {
    return status;
}

const std::vector<unsigned int>& Stage::getTaskIds() const {
    return taskIds;
}

void Stage::start() {
    status = StageStatus::Active;
}

void Stage::finish() {
    status = StageStatus::Finished;
}

void Stage::addTask(unsigned int taskId) {
    if (!containsTask(taskId)) {
        taskIds.push_back(taskId);
    }
}

void Stage::removeTask(unsigned int taskId) {
    taskIds.erase(std::remove(taskIds.begin(), taskIds.end(), taskId), taskIds.end());
}

bool Stage::containsTask(unsigned int taskId) const {
    return std::find(taskIds.begin(), taskIds.end(), taskId) != taskIds.end();
}

void Stage::serialize(std::ostream& os) const {
    os << name << '\n'
        << startDate << '\n'
        << endDate << '\n'
        << stageStatusToString(status) << '\n';

    os << taskIds.size() << '\n';

    for (unsigned int taskId : taskIds) {
        os << taskId << '\n';
    }
}

Stage Stage::deserialize(std::istream& is) {
    std::string name;
    std::time_t startDate;
    std::time_t endDate;
    std::string statusStr;
    size_t taskCount;

    std::getline(is, name);

    is >> startDate;
    is.ignore();

    is >> endDate;
    is.ignore();

    std::getline(is, statusStr);

    is >> taskCount;
    is.ignore();

    std::vector<unsigned int> taskIds;

    for (size_t i = 0; i < taskCount; i++) {
        unsigned int taskId;
        is >> taskId;
        is.ignore();

        taskIds.push_back(taskId);
    }

    return Stage(name, startDate, endDate, stringToStageStatus(statusStr), taskIds);
}

void Stage::print(std::ostream& os) const {
    os << "Stage: " << name << '\n'
        << "Start date: " << startDate << '\n'
        << "End date: " << endDate << '\n'
        << "Status: " << stageStatusToString(status) << '\n'
        << "Tasks count: " << taskIds.size() << '\n';
}

std::ostream& operator<<(std::ostream& os, const Stage& stage) {
    stage.print(os);
    return os;
}