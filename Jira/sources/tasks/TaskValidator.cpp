#include "../../headers/tasks/TaskValidator.h"
#include <stdexcept>
#include <ctime>

void TaskValidator::validateTitle(
    const std::string& title) {

    if (title.empty()) {
        throw std::invalid_argument(
            "Task title cannot be empty.");
    }

    if (title.size() > 100) {
        throw std::invalid_argument(
            "Task title is too long.");
    }
}

void TaskValidator::validatePoints(
    int points) {

    if (points < 0) {
        throw std::invalid_argument(
            "Task points cannot be negative.");
    }
}

void TaskValidator::validateGrade(
    double grade) {

    if (grade < 2.0 || grade > 6.0) {
        throw std::invalid_argument(
            "Invalid grade.");
    }
}

void TaskValidator::validateDeadline(
    std::time_t deadline) {

    std::time_t now =
        std::time(nullptr);

    if (deadline < now) {
        throw std::invalid_argument(
            "Deadline cannot be in the past.");
    }
}