#pragma once
#include <string>
#include "../Context.h"
#include "../tasks/Task.h"

class TaskService {
public:
    static void createTask(Context& context, const std::string& projectName, const std::string& title, const std::string& description, TaskType type, TaskPriority priority, std::time_t deadline, int points);

    static Task* findTaskById(Context& context, unsigned int taskId);

    static void assignTask(Context& context, unsigned int taskId);

    static void changeStatus(Context& context, unsigned int taskId, TaskStatus newStatus);

    static void changePriority(Context& context, unsigned int taskId, TaskPriority newPriority);

    static void gradeTask(Context& context, unsigned int taskId, double grade);

    static void addComment(Context& context, unsigned int taskId, const std::string& content);

private:
    static void requireStudent(Context& context);
    static void requireTeachingAssistantOrLecturer(Context& context);
    static void requireLecturer(Context& context);

    static Project* getProjectForTask(Context& context, unsigned int taskId);
    static bool isValidStatusTransition(TaskStatus currentStatus, TaskStatus newStatus);

};