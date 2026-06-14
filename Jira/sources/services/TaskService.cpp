#include "../../headers/services/TaskService.h"

#include "../../headers/services/UserService.h"
#include "../../headers/services/ProjectService.h"
#include "../../headers/tasks/TaskFactory.h"
#include "../../headers/tasks/TaskValidator.h"
#include "../../headers/Comment.h"
#include "../../headers/users/UserRole.hpp"

#include <stdexcept>

void TaskService::createTask(Context& context, const std::string& projectName, const std::string& title, const std::string& description, TaskType type, TaskPriority priority)
{
	requireStudent(context);


	User* user = UserService::getCurrentUser(context);

	Project* project = ProjectService::findProjectByName(context, projectName);

	if (project == nullptr)
	{
		throw std::invalid_argument("This project does not exist.");
	}

	if (project->getStatus() == ProjectStatus::Finished)
	{
		throw std::invalid_argument("Cannot add task to finished project");
	}

	if (!project->containsMember(user->getId()))
	{
		throw std::invalid_argument("You are not part of this project.");
	}

	Task task = TaskFactory::createTask(title, description, type, priority, user->getId());

	unsigned int taskId = task.getId();

	project->addTask(taskId);

	context.getTasks().push_back(task);

	context.markChanged();

}

Task* TaskService::findTaskById(Context& context, unsigned int taskId)
{
	for ( Task& task : context.getTasks())
	{
		if (task.getId() == taskId)
		{
			return &task;
		}
	}

	return nullptr;
}

void TaskService::assignTask(Context& context, unsigned int taskId) {
	requireStudent(context);

	User* currentUser = UserService::getCurrentUser(context);

	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	Project* project = ProjectService::findProjectByTaskId(context, taskId);

	if (project == nullptr) {
		throw std::runtime_error("Task is not connected to project.");
	}

	if (!project->containsMember(currentUser->getId())) {
		throw std::runtime_error("You are not a member of this project.");
	}

	if (project->getStatus() == ProjectStatus::Finished) {
		throw std::runtime_error("Cannot assign task in finished project.");
	}

	if (task->getAssigneeId() != 0) {
		throw std::runtime_error("Task is already assigned.");
	}

	if (task->getStatus() != TaskStatus::ToDo) {
		throw std::runtime_error("Only ToDo tasks can be assigned.");
	}

	task->assignTo(currentUser->getId());

	context.markChanged();
}

void TaskService::changeStatus(Context& context, unsigned int taskId, TaskStatus newStatus) {
	requireStudent(context);

	User* currentUser = UserService::getCurrentUser(context);

	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	if (task->getAssigneeId() != currentUser->getId()) {
		throw std::runtime_error("You can change status only of tasks assigned to you.");
	}

	if (task->getStatus() == newStatus) {
		throw std::runtime_error("Task already has this status.");
	}

	if (task->getStatus() == TaskStatus::Done) {
		throw std::runtime_error("Cannot change status of completed task.");
	}

	if (!isValidStatusTransition(task->getStatus(), newStatus)) {
		throw std::runtime_error("Invalid task status transition.");
	}

	task->changeStatus(newStatus);

	context.markChanged();
}

void TaskService::changePriority(Context& context, unsigned int taskId, TaskPriority newPriority)
{
	requireTeachingAssistantOrLecturer(context);

	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	Project* project = getProjectForTask(context, taskId);

	if (project == nullptr) {
		throw std::runtime_error("Task is not connected to any project.");
	}

	if (project->getStatus() == ProjectStatus::Finished) {
		throw std::runtime_error("Cannot change priority of task in finished project.");
	}

	if (task->getStatus() == TaskStatus::Done) {
		throw std::runtime_error("Cannot change priority of completed task.");
	}

	if (task->getPriority() == newPriority) {
		throw std::runtime_error("Task already has this priority.");
	}

	task->changePriority(newPriority);

	context.markChanged();
}

void TaskService::gradeTask(Context& context, unsigned int taskId, double grade) {
	requireLecturer(context);

	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	Project* project = getProjectForTask(context, taskId);

	if (project == nullptr) {
		throw std::runtime_error("Task is not connected to any project.");
	}

	if (task->getStatus() != TaskStatus::Done) {
		throw std::runtime_error("Only completed tasks can be graded.");
	}

	
	TaskValidator::validateGrade(grade);

	task->setPoints(10 - (6-grade)*2);
	task->setGrade(grade);

	context.markChanged();
}

void TaskService::addComment(Context& context, unsigned int taskId, const std::string& content)
{
	if (!context.isUserLoggedIn()) {
		throw std::runtime_error("No logged user.");
	}

	Task* task = findTaskById(context, taskId);

	User* currentUser = UserService::getCurrentUser(context);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	if (content.empty()) {
		throw std::invalid_argument("Comment cannot be empty.");
	}

	task->addComment(Comment(currentUser->getId(), content));

	context.markChanged();


}

void TaskService::requireStudent(Context& context)
{
	User* currentUser = UserService::getCurrentUser(context);

	if (currentUser == nullptr) {
		throw std::runtime_error("No logged user.");
	}

	if (currentUser->getRole() != UserRole::Student) {
		throw std::runtime_error("Only student can perform this action.");
	}
}

void TaskService::requireTeachingAssistantOrLecturer(Context& context)
{
	User* currentUser = UserService::getCurrentUser(context);

	if (currentUser == nullptr)
	{
		throw std::runtime_error("No logged user");
	}

	UserRole role = currentUser->getRole();

	if (role != UserRole::TeachingAssistant && role != UserRole::Lecturer) {
		throw std::runtime_error("Only teaching assistant or lecturer can perform this action.");
	}

}

void TaskService::requireLecturer(Context& context)
{

	User* currentUser = UserService::getCurrentUser(context);

	if (currentUser == nullptr)
	{
		throw std::runtime_error("No logged user");
	}

	if (currentUser->getRole() != UserRole::Lecturer)
	{
		throw std::runtime_error("Only lecturer can perform this action.");
	}
}

Project* TaskService::getProjectForTask(Context& context, unsigned int taskId) {
	return ProjectService::findProjectByTaskId(context, taskId);
}

bool TaskService::isValidStatusTransition(TaskStatus currentStatus, TaskStatus newStatus) {
	if (currentStatus == TaskStatus::ToDo && newStatus == TaskStatus::InProgress) {
		return true;
	}
	else if (currentStatus == TaskStatus::InProgress && newStatus == TaskStatus::InReview) {
		return true;
	}
	else if (currentStatus == TaskStatus::InReview && newStatus == TaskStatus::Done) {
		return true;
	}

	return false;
}

void TaskService::addTag(Context& context, unsigned int taskId, const std::string& tag) {
	requireTeachingAssistantOrLecturer(context);

	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	if (tag.empty()) {
		throw std::invalid_argument("Tag cannot be empty.");
	}

	task->addTag(tag);

	context.markChanged();
}

const std::vector<std::string>& TaskService::getHistory(Context& context, unsigned int taskId) {
	Task* task = findTaskById(context, taskId);

	if (task == nullptr) {
		throw std::invalid_argument("Task does not exist.");
	}

	return task->getHistory();
}

std::vector<Task*> TaskService::searchTasks(Context& context, const std::string& keyword) {
	std::vector<Task*> result;

	for (Task& task : context.getTasks()) {
		if (task.getTitle().find(keyword) != std::string::npos ||
			task.getDescription().find(keyword) != std::string::npos) {

			result.push_back(&task);
		}
	}

	return result;
}

std::vector<Task*> TaskService::filterByStatus(Context& context, TaskStatus status) {
	std::vector<Task*> result;

	for (Task& task : context.getTasks()) {
		if (task.getStatus() == status) {
			result.push_back(&task);
		}
	}

	return result;
}