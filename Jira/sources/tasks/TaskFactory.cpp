#include "../../headers/tasks/TaskFactory.h"
#include "../../headers/tasks/TaskValidator.h"

Task TaskFactory::createTask(const std::string& title, const std::string& description, TaskType type, TaskPriority priority, unsigned int creatorId, std::time_t deadline, int points) {
    TaskValidator::validateTitle(title);
    TaskValidator::validatePoints(points);
    TaskValidator::validateDeadline(deadline);

    return Task(title, description, type, priority, creatorId, deadline, points);
}

Task TaskFactory::restoreTask(unsigned int id, const std::string& title, const std::string& description, TaskType type, TaskPriority priority, TaskStatus status, unsigned int creatorId, unsigned int assigneeId, std::time_t deadline, int points, double grade, const std::vector<Comment>& comments, const std::vector<std::string>& tags, const std::vector<std::string>& history) {
    return Task(id, title, description, type, priority, status, creatorId, assigneeId, deadline, points, grade, comments, tags, history);
}