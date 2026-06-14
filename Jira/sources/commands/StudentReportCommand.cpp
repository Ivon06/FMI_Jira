
#include "../../headers/commands/StudentReportCommand.h"
#include "../../headers/services/UserService.h"

#include <iostream>
#include <stdexcept>

StudentReportCommand::StudentReportCommand(const std::vector<std::string>& args)
    : Command(args) {
}

void StudentReportCommand::execute(Context& context) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: student-report <username>");
    }

    User* currentUser = UserService::getCurrentUser(context);

    if (currentUser == nullptr || currentUser->getRole() != UserRole::Lecturer) {
        throw std::runtime_error("Only lecturer can view student reports.");
    }

    User* student = UserService::findUserByUsername(context, args[0]);

    if (student == nullptr || student->getRole() != UserRole::Student) {
        throw std::invalid_argument("Student does not exist.");
    }

    int completed = 0;
    int inProgress = 0;
    int score = 0;

    for (const Task& task : context.getTasks()) {
        if (task.getAssigneeId() == student->getId()) {
            if (task.getStatus() == TaskStatus::Done) {
                completed++;
                score += task.getPoints();
            }
            else {
                inProgress++;
            }
        }
    }

    std::cout << "[Student Report]" << std::endl;
    std::cout << "Username: " << student->getUsername() << std::endl;
    std::cout << "Completed tasks: " << completed << std::endl;
    std::cout << "In progress tasks: " << inProgress << std::endl;
    std::cout << "Performance score: " << score << std::endl;
}