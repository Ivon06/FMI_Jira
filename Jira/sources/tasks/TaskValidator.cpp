#include "../../headers/tasks/TaskValidator.h"
#include "../../headers/Constants.h"
#include <stdexcept>
#include <ctime>

void TaskValidator::validateTitle(const std::string& title) {
    if (title.empty()) {
        throw std::invalid_argument("Task title cannot be empty.");
    }

    if (title.size() > Constants::Task::MAX_TITLE_LENGTH) {
        throw std::invalid_argument("Task title is too long.");
    }
}

void TaskValidator::validatePoints(int points) {
    if (points < Constants::Task::MIN_POINTS) {
        throw std::invalid_argument("Task points cannot be negative.");
    }
}

void TaskValidator::validateGrade(double grade) {
    if (grade < Constants::Task::MIN_GRADE ||
        grade > Constants::Task::MAX_GRADE) {
        throw std::invalid_argument("Invalid grade.");
    }
}

void TaskValidator::validateDeadline(std::time_t deadline) {
    if (deadline < std::time(nullptr)) {
        throw std::invalid_argument("Deadline cannot be in the past.");
    }
}