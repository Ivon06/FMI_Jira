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

Task::Task(const std::string& title,
    const std::string& description,
    TaskType type,
    TaskPriority priority,
    unsigned int creatorId,
    std::time_t deadline,
    int points)
    : id(nextId++),
    title(title),
    description(description),
    type(type),
    priority(priority),
    status(TaskStatus::ToDo),
    creatorId(creatorId),
    assigneeId(0),
    deadline(deadline),
    points(points),
    grade(0.0) {
}

Task::Task(unsigned int id,
    const std::string& title,
    const std::string& description,
    TaskType type,
    TaskPriority priority,
    TaskStatus status,
    unsigned int creatorId,
    unsigned int assigneeId,
    std::time_t deadline,
    int points,
    double grade)
    : id(id),
    title(title),
    description(description),
    type(type),
    priority(priority),
    status(status),
    creatorId(creatorId),
    assigneeId(assigneeId),
    deadline(deadline),
    points(points),
    grade(grade) {

    if (id >= nextId) {
        nextId = id + 1;
    }
}

void Task::print(std::ostream& os) const {

    os << "Task ID: "
        << id
        << '\n';

    os << "Title: "
        << title
        << '\n';

    os << "Description: "
        << description
        << '\n';

    os << "Type: "
        << taskTypeToString(type)
        << '\n';

    os << "Priority: "
        << taskPriorityToString(priority)
        << '\n';

    os << "Status: "
        << taskStatusToString(status)
        << '\n';

    os << "Creator ID: "
        << creatorId
        << '\n';

    os << "Assignee ID: "
        << assigneeId
        << '\n';

    os << "Points: "
        << points
        << '\n';

    os << "Grade: "
        << grade
        << '\n';
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

    addHistoryEntry(
        "Task assigned.");
}

void Task::changeStatus(TaskStatus newStatus) {

    status = newStatus;

    addHistoryEntry(
        "Task status changed.");
}

void Task::changePriority(TaskPriority newPriority) {

    priority = newPriority;

    addHistoryEntry(
        "Task priority changed.");
}

void Task::setGrade(double grade) {

    if (grade < 2.0 || grade > 6.0) {
        throw std::invalid_argument(
            "Invalid grade.");
    }

    this->grade = grade;

    addHistoryEntry(
        "Task graded.");
}

void Task::addComment(const Comment& comment) {
    comments.push_back(comment);
}

void Task::addTag(const std::string& tag) {
    tags.push_back(tag);
}

void Task::addHistoryEntry(
    const std::string& entry) {

    history.push_back(entry);
}

bool Task::isCompleted() const {
    return status == TaskStatus::Done;
}

void Task::serialize(std::ostream& os) const {

    os << id << '\n'
        << title << '\n'
        << description << '\n'
        << static_cast<int>(type) << '\n'
        << static_cast<int>(priority) << '\n'
        << static_cast<int>(status) << '\n'
        << creatorId << '\n'
        << assigneeId << '\n'
        << deadline << '\n'
        << points << '\n'
        << grade << '\n';
}

std::ostream& operator<<(std::ostream& os,
    const Task& task) {

    task.print(os);

    return os;
}