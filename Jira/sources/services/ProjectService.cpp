#include "../../headers/services/ProjectService.h"

#include "../../headers/services/UserService.h"
#include "../../headers/projects/ProjectValidator.h"

#include <stdexcept>

void ProjectService::createProject(Context& context, const std::string& name, const std::string& description) {
    requireAdmin(context);

    ProjectValidator::validateName(name);
    ProjectValidator::validateDescription(description);

    if (projectExists(context, name)) {
        throw std::invalid_argument("Project already exists.");
    }

    context.getProjects().push_back(
        Project(name, description)
    );

    context.markChanged();
}

Project* ProjectService::findProjectByName(Context& context,  const std::string& name) {
    for (Project& project : context.getProjects()) {
        if (project.getName() == name) {
            return &project;
        }
    }

    return nullptr;
}

Project* ProjectService::findProjectById(Context& context, unsigned int id) {
    for (Project& project : context.getProjects()) {
        if (project.getId() == id) {
            return &project;
        }
    }

    return nullptr;
}

bool ProjectService::projectExists(Context& context, const std::string& name) {
    return findProjectByName(context, name) != nullptr;
}

void ProjectService::addUserToProject(Context& context, const std::string& username, const std::string& projectName) {
    requireAdmin(context);

    User* user = UserService::findUserByUsername(context, username);

    if (user == nullptr) {
        throw std::invalid_argument("User does not exist.");
    }

    Project* project = findProjectByName(context, projectName);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    if (project->getStatus() == ProjectStatus::Finished) {
        throw std::runtime_error("Cannot add users to finished project.");
    }

    project->addMember(user->getId());

    context.markChanged();
}

void ProjectService::archiveProject(Context& context, const std::string& projectName) {
    requireAdmin(context);

    Project* project = findProjectByName(context, projectName);

    if (project == nullptr) {
        throw std::invalid_argument("Project does not exist.");
    }

    project->finalize();

    context.markChanged();
}

void ProjectService::requireAdmin( Context& context) {

    User* currentUser =
        UserService::getCurrentUser(
            context);

    if (currentUser == nullptr) {
        throw std::runtime_error(
            "No logged user.");
    }

    if (currentUser->getRole()
        != UserRole::Administrator) {

        throw std::runtime_error(
            "Only administrator can perform this action.");
    }
}