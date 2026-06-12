#include "../../headers/services/DataService.h"

#include "../../headers/users/UserFactory.h"
#include "../../headers/users/Administrator.h"

#include <fstream>
#include <stdexcept>
#include <memory>

void DataService::save(Context& context) {
    saveUsers(context, "users.txt");
    saveProjects(context, "projects.txt");
    saveTasks(context, "tasks.txt");

    context.markSaved();
}

void DataService::load(Context& context) {
    context.getUsers().clear();
    context.getProjects().clear();
    context.getTasks().clear();

    if (fileExists("users.txt")) {
        loadUsers(context, "users.txt");
    }
    else {
        seedAdmin(context);
    }

    if (fileExists("projects.txt")) {
        loadProjects(context, "projects.txt");
    }

    if (fileExists("tasks.txt")) {
        loadTasks(context, "tasks.txt");
    }

    context.clearCurrentUser();
    context.markSaved();
}

bool DataService::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void DataService::seedAdmin(Context& context) {
    context.getUsers().push_back(std::make_unique<Administrator>("admin", "admin"));
}

void DataService::saveUsers(Context& context, const std::string& filename) {
    std::ofstream ofs(filename);

    if (!ofs.is_open()) {
        throw std::runtime_error("Cannot open users file for writing.");
    }

    ofs << context.getUsers().size() << '\n';

    for (const auto& user : context.getUsers()) {
        user->serialize(ofs);
    }

    ofs.close();
}

void DataService::loadUsers(Context& context, const std::string& filename) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open users file for reading.");
    }

    size_t count = 0;

    if (!(ifs >> count)) {
        seedAdmin(context);
        return;
    }

    ifs.ignore();

    bool hasAdmin = false;

    for (size_t i = 0; i < count; i++) {
        unsigned int id;
        std::string username;
        std::string password;
        std::string role;

        ifs >> id;
        ifs.ignore();

        std::getline(ifs, username);
        std::getline(ifs, password);
        std::getline(ifs, role);

        std::unique_ptr<User> user = UserFactory::restoreUser(id, username, password, role);

        if (user->getRole() == UserRole::Administrator) {
            if (hasAdmin) {
                throw std::runtime_error("Invalid data: more than one administrator.");
            }

            hasAdmin = true;
        }

        context.getUsers().push_back(std::move(user));
    }

    if (!hasAdmin) {
        seedAdmin(context);
    }

    ifs.close();
}

void DataService::saveProjects(Context& context, const std::string& filename) {
    std::ofstream ofs(filename);

    if (!ofs.is_open()) {
        throw std::runtime_error("Cannot open projects file for writing.");
    }

    ofs << context.getProjects().size() << '\n';

    for (const Project& project : context.getProjects()) {
        project.serialize(ofs);
    }

    ofs.close();
}

void DataService::loadProjects(Context& context, const std::string& filename) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open projects file for reading.");
    }

    size_t count = 0;
    ifs >> count;
    ifs.ignore();

    for (size_t i = 0; i < count; i++) {
        context.getProjects().push_back(Project::deserialize(ifs));
    }

    ifs.close();
}

void DataService::saveTasks(Context& context, const std::string& filename) {
    std::ofstream ofs(filename);

    if (!ofs.is_open()) {
        throw std::runtime_error("Cannot open tasks file for writing.");
    }

    ofs << context.getTasks().size() << '\n';

    for (const Task& task : context.getTasks()) {
        task.serialize(ofs);
    }

    ofs.close();
}

void DataService::loadTasks(Context& context, const std::string& filename) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open tasks file for reading.");
    }

    size_t count = 0;
    ifs >> count;
    ifs.ignore();

    for (size_t i = 0; i < count; i++) {
        context.getTasks().push_back(Task::deserialize(ifs));
    }

    ifs.close();
}