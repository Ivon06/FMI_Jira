#include "../../headers/tasks/Task.h"
#include <stdexcept>

unsigned int Task::nextId = 1;

std::string taskTypeToString(TaskType type) {

    switch (type) {

    case TaskType::Bug:
        return "Bug";

    case TaskType::Feature:
        return "Feature";

    case TaskType::Task:
        return "Task";

    case TaskType::Improvement:
        return "Improvement";

    default:
        return "Unknown";
    }
}

std::string taskPriorityToString(TaskPriority priority) {

    switch (priority) {

    case TaskPriority::Low:
        return "Low";

    case TaskPriority::Medium:
        return "Medium";

    case TaskPriority::High:
        return "High";

    case TaskPriority::Critical:
        return "Critical";

    default:
        return "Unknown";
    }
}

std::string taskStatusToString(TaskStatus status) {

    switch (status) {

    case TaskStatus::ToDo:
        return "ToDo";

    case TaskStatus::InProgress:
        return "InProgress";

    case TaskStatus::InReview:
        return "InReview";

    case TaskStatus::Done:
        return "Done";

    default:
        return "Unknown";
    }
}

Task::Task(const std::string& title, const std::string& description, TaskType type, TaskPriority priority, unsigned int creatorId, std::time_t deadline, int points)
    : id(nextId++), title(title), description(description), type(type), priority(priority), status(TaskStatus::ToDo), creatorId(creatorId), assigneeId(0), deadline(deadline), points(points), grade(0.0) {
}

Task::Task(unsigned int id, const std::string& title, const std::string& description, TaskType type, TaskPriority priority, TaskStatus status, unsigned int creatorId, unsigned int assigneeId, std::time_t deadline, int points, double grade, const std::vector<Comment>& comments, const std::vector<std::string>& tags, const std::vector<std::string>& history)
    : id(id), title(title), description(description), type(type), priority(priority), status(status), creatorId(creatorId), assigneeId(assigneeId), deadline(deadline), points(points), grade(grade), comments(comments), tags(tags), history(history) {
    if (id >= nextId) {
        nextId = id + 1;
    }
}

unsigned int Task::getId() const {
    return id;
}

const std::string& Task::getTitle() const {
    return title;
}

const std::string& Task::getDescription() const {
    return description;
}

TaskType Task::getType() const {
    return type;
}

TaskPriority Task::getPriority() const {
    return priority;
}

TaskStatus Task::getStatus() const {
    return status;
}

unsigned int Task::getCreatorId() const {
    return creatorId;
}

unsigned int Task::getAssigneeId() const {
    return assigneeId;
}

std::time_t Task::getDeadline() const {
    return deadline;
}

int Task::getPoints() const {
    return points;
}

double Task::getGrade() const {
    return grade;
}

const std::vector<Comment>& Task::getComments() const {
    return comments;
}

const std::vector<std::string>& Task::getTags() const {
    return tags;
}

const std::vector<std::string>& Task::getHistory() const {
    return history;
}

void Task::assignTo(unsigned int assigneeId) {

    this->assigneeId = assigneeId;

    addHistoryEntry("Task assigned.");
}

void Task::changeStatus(TaskStatus newStatus) {

    status = newStatus;

    addHistoryEntry("Task status changed.");
}

void Task::changePriority(TaskPriority newPriority) {

    priority = newPriority;

    addHistoryEntry("Task priority changed.");
}

void Task::setGrade(double grade) {

    if (grade < 2.0 || grade > 6.0) {
        throw std::invalid_argument(
            "Invalid grade.");
    }

    this->grade = grade;

    addHistoryEntry("Task graded.");
}

void Task::addComment(const Comment& comment) {
    comments.push_back(comment);
}

void Task::addTag(const std::string& tag) {
    tags.push_back(tag);
}

void Task::addHistoryEntry(const std::string& entry) {

    history.push_back(entry);
}

bool Task::isCompleted() const {
    return status == TaskStatus::Done;
}

void Task::serialize(std::ostream& os) const {
    os << id << '\n';
    os << title << '\n';
    os << description << '\n';
    os << taskTypeToString(type) << '\n';
    os << taskPriorityToString(priority) << '\n';
    os << taskStatusToString(status) << '\n';
    os << creatorId << '\n';
    os << assigneeId << '\n';
    os << deadline << '\n';
    os << points << '\n';
    os << grade << '\n';

    os << comments.size() << '\n';
    for (const Comment& comment : comments) {
        comment.serialize(os);
    }

    os << tags.size() << '\n';
    for (const std::string& tag : tags) {
        os << tag << '\n';
    }

    os << history.size() << '\n';
    for (const std::string& entry : history) {
        os << entry << '\n';
    }
}

Task Task::deserialize(std::istream& is) {
    unsigned int id;
    std::string title;
    std::string description;
    std::string typeStr;
    std::string priorityStr;
    std::string statusStr;
    unsigned int creatorId;
    unsigned int assigneeId;
    std::time_t deadline;
    int points;
    double grade;

    is >> id;
    is.ignore();

    std::getline(is, title);
    std::getline(is, description);
    std::getline(is, typeStr);
    std::getline(is, priorityStr);
    std::getline(is, statusStr);

    is >> creatorId;
    is.ignore();

    is >> assigneeId;
    is.ignore();

    is >> deadline;
    is.ignore();

    is >> points;
    is.ignore();

    is >> grade;
    is.ignore();

    size_t commentsCount;
    is >> commentsCount;
    is.ignore();

    std::vector<Comment> comments;
    for (size_t i = 0; i < commentsCount; i++) {
        comments.push_back(Comment::deserialize(is));
    }

    size_t tagsCount;
    is >> tagsCount;
    is.ignore();

    std::vector<std::string> tags;
    for (size_t i = 0; i < tagsCount; i++) {
        std::string tag;
        std::getline(is, tag);
        tags.push_back(tag);
    }

    size_t historyCount;
    is >> historyCount;
    is.ignore();

    std::vector<std::string> history;
    for (size_t i = 0; i < historyCount; i++) {
        std::string entry;
        std::getline(is, entry);
        history.push_back(entry);
    }

    return Task(id, title, description, stringToTaskType(typeStr), stringToTaskPriority(priorityStr), stringToTaskStatus(statusStr), creatorId, assigneeId, deadline, points, grade, comments, tags, history);
}

std::ostream& operator<<(std::ostream& os, const Task& task) {

    task.print(os);

    return os;
}

void Task::print(std::ostream& os) const {
    os << "Task ID: " << id << '\n';
    os << "Title: " << title << '\n';
    os << "Description: " << description << '\n';
    os << "Type: " << taskTypeToString(type) << '\n';
    os << "Priority: " << taskPriorityToString(priority) << '\n';
    os << "Status: " << taskStatusToString(status) << '\n';
    os << "Creator ID: " << creatorId << '\n';
    os << "Assignee ID: " << assigneeId << '\n';
    os << "Deadline: " << deadline << '\n';
    os << "Points: " << points << '\n';
    os << "Grade: " << grade << '\n';
}