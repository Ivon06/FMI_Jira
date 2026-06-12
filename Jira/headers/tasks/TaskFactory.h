#pragma once
#include "Task.h"

class TaskFactory {
public:
    static Task createTask(const std::string& title, const std::string& description, TaskType type, TaskPriority priority, unsigned int creatorId);

    static Task restoreTask(unsigned int id, const std::string& title, const std::string& description, TaskType type, TaskPriority priority, TaskStatus status, unsigned int creatorId, unsigned int assigneeId, std::time_t deadline, int points, double grade, const std::vector<Comment>& comments, const std::vector<std::string>& tags, const std::vector<std::string>& history);
};