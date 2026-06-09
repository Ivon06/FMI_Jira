#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "../Comment.h"

enum class TaskType {
    Bug,
    Feature,
    Task,
    Improvement
};

enum class TaskPriority {
    Low,
    Medium,
    High,
    Critical
};

enum class TaskStatus {
    ToDo,
    InProgress,
    InReview,
    Done
};

std::string taskTypeToString(TaskType type);
std::string taskPriorityToString(TaskPriority priority);
std::string taskStatusToString(TaskStatus status);



class Task {
private:
    static unsigned int nextId;

    unsigned int id;

    std::string title;
    std::string description;

    TaskType type;
    TaskPriority priority;
    TaskStatus status;

    unsigned int creatorId;
    unsigned int assigneeId;

    std::time_t deadline;

    int points;
    double grade;

    std::vector<Comment> comments;
    std::vector<std::string> tags;
    std::vector<std::string> history;

protected:
    void print(std::ostream& os) const;

public:
    Task(const std::string& title,
        const std::string& description,
        TaskType type,
        TaskPriority priority,
        unsigned int creatorId,
        std::time_t deadline,
        int points);

    Task(unsigned int id,
        const std::string& title,
        const std::string& description,
        TaskType type,
        TaskPriority priority,
        TaskStatus status,
        unsigned int creatorId,
        unsigned int assigneeId,
        std::time_t deadline,
        int points,
        double grade);

    unsigned int getId() const;

    const std::string& getTitle() const;

    const std::string& getDescription() const;

    TaskType getType() const;

    TaskPriority getPriority() const;

    TaskStatus getStatus() const;

    unsigned int getCreatorId() const;

    unsigned int getAssigneeId() const;

    std::time_t getDeadline() const;

    int getPoints() const;

    double getGrade() const;

    const std::vector<Comment>& getComments() const;

    const std::vector<std::string>& getTags() const;

    const std::vector<std::string>& getHistory() const;

    void assignTo(unsigned int assigneeId);

    void changeStatus(TaskStatus newStatus);

    void changePriority(TaskPriority newPriority);

    void setGrade(double grade);

    void addComment(const Comment& comment);

    void addTag(const std::string& tag);

    void addHistoryEntry(const std::string& entry);

    bool isCompleted() const;

    void serialize(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os,
        const Task& task);
};


inline TaskType stringToTaskType(const std::string& str) {
    if (str == "Bug") return TaskType::Bug;
    if (str == "Feature") return TaskType::Feature;
    if (str == "Task") return TaskType::Task;
    if (str == "Improvement") return TaskType::Improvement;

    throw std::invalid_argument("Invalid task type.");
}

inline TaskPriority stringToTaskPriority(const std::string& str) {
    if (str == "Low") return TaskPriority::Low;
    if (str == "Medium") return TaskPriority::Medium;
    if (str == "High") return TaskPriority::High;
    if (str == "Critical") return TaskPriority::Critical;

    throw std::invalid_argument("Invalid task priority.");
}

inline TaskStatus stringToTaskStatus(const std::string& str) {
    if (str == "ToDo") return TaskStatus::ToDo;
    if (str == "InProgress") return TaskStatus::InProgress;
    if (str == "InReview") return TaskStatus::InReview;
    if (str == "Done") return TaskStatus::Done;

    throw std::invalid_argument("Invalid task status.");
}