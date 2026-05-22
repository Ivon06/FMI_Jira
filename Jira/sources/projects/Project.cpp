#include "../../headers/projects/Project.h"
#include <algorithm>

unsigned int Project::nextId = 1;

std::string projectStatusToString(
    ProjectStatus status) {

    switch (status) {

    case ProjectStatus::Active:
        return "Active";

    case ProjectStatus::Finished:
        return "Finished";

    default:
        return "Unknown";
    }
}

Project::Project(const std::string& name,
    const std::string& description)
    : id(nextId++),
    name(name),
    description(description),
    status(ProjectStatus::Active) {
}

Project::Project(unsigned int id,
    const std::string& name,
    const std::string& description,
    ProjectStatus status)
    : id(id),
    name(name),
    description(description),
    status(status) {

    if (id >= nextId) {
        nextId = id + 1;
    }
}

unsigned int Project::getId() const {
    return id;
}

const std::string& Project::getName() const {
    return name;
}

const std::string& Project::getDescription() const {
    return description;
}

ProjectStatus Project::getStatus() const {
    return status;
}

const std::vector<unsigned int>&
Project::getMemberIds() const {

    return memberIds;
}

const std::vector<unsigned int>&
Project::getTaskIds() const {

    return taskIds;
}

const std::vector<Stage>&
Project::getStages() const {

    return stages;
}

void Project::addMember(unsigned int userId) {

    if (!containsMember(userId)) {
        memberIds.push_back(userId);
    }
}

void Project::removeMember(
    unsigned int userId) {

    memberIds.erase(
        std::remove(memberIds.begin(),
            memberIds.end(),
            userId),
        memberIds.end());
}

bool Project::containsMember(
    unsigned int userId) const {

    return std::find(memberIds.begin(),
        memberIds.end(),
        userId)
        != memberIds.end();
}

void Project::addTask(unsigned int taskId) {

    if (!containsTask(taskId)) {
        taskIds.push_back(taskId);
    }
}

bool Project::containsTask(
    unsigned int taskId) const {

    return std::find(taskIds.begin(),
        taskIds.end(),
        taskId)
        != taskIds.end();
}

void Project::addStage(
    const Stage& stage) {

    if (!containsStage(stage.getName())) {
        stages.push_back(stage);
    }
}

Stage* Project::getStageByName(
    const std::string& stageName) {

    for (Stage& stage : stages) {

        if (stage.getName() == stageName) {
            return &stage;
        }
    }

    return nullptr;
}

const Stage* Project::getStageByName(
    const std::string& stageName) const {

    for (const Stage& stage : stages) {

        if (stage.getName() == stageName) {
            return &stage;
        }
    }

    return nullptr;
}

bool Project::containsStage(
    const std::string& stageName) const {

    return getStageByName(stageName)
        != nullptr;
}

void Project::finalize() {
    status = ProjectStatus::Finished;
}

void Project::serialize(
    std::ostream& os) const {

    os << id << '\n'
        << name << '\n'
        << description << '\n'
        << static_cast<int>(status)
        << '\n';

    os << memberIds.size()
        << '\n';

    for (unsigned int id : memberIds) {
        os << id << ' ';
    }

    os << '\n';

    os << taskIds.size()
        << '\n';

    for (unsigned int id : taskIds) {
        os << id << ' ';
    }

    os << '\n';

    os << stages.size()
        << '\n';

    for (const Stage& stage : stages) {
        stage.serialize(os);
    }
}

void Project::print(
    std::ostream& os) const {

    os << "Project ID: "
        << id
        << '\n';

    os << "Name: "
        << name
        << '\n';

    os << "Description: "
        << description
        << '\n';

    os << "Status: "
        << projectStatusToString(status)
        << '\n';

    os << "Members count: "
        << memberIds.size()
        << '\n';

    os << "Tasks count: "
        << taskIds.size()
        << '\n';

    os << "Stages count: "
        << stages.size()
        << '\n';
}

std::ostream& operator<<(
    std::ostream& os,
    const Project& project) {

    project.print(os);

    return os;
}