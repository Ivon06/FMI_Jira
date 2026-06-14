#include "../../headers/projects/Project.h"
#include <algorithm>

unsigned int Project::nextId = 1;

std::string projectStatusToString(ProjectStatus status) {
    if (status == ProjectStatus::Active) {
        return "Active";
    }
    else if (status == ProjectStatus::Finished) {
        return "Finished";
    }

    throw std::invalid_argument("Invalid project status.");
}

ProjectStatus stringToProjectStatus(const std::string& str) {
    if (str == "Active") {
        return ProjectStatus::Active;
    }
    else if (str == "Finished") {
        return ProjectStatus::Finished;
    }

    throw std::invalid_argument("Invalid project status.");
}

Project::Project(const std::string& name, const std::string& description)
    : id(nextId++), name(name), description(description), status(ProjectStatus::Active) {
}

Project::Project(unsigned int id, const std::string& name, const std::string& description, ProjectStatus status, const std::vector<unsigned int>& memberIds, const std::vector<unsigned int>& taskIds, const std::vector<Stage>& stages)
    : id(id), name(name), description(description), memberIds(memberIds), taskIds(taskIds), stages(stages), status(status) {
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

void Project::removeMember(unsigned int userId) {

    memberIds.erase(
        std::remove(memberIds.begin(),
            memberIds.end(),
            userId),
        memberIds.end());
}

bool Project::containsMember(unsigned int userId) const {

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

bool Project::containsTask(unsigned int taskId) const {

    return std::find(taskIds.begin(),
        taskIds.end(),
        taskId)
        != taskIds.end();
}

void Project::addStage(const Stage& stage) {

    if (!containsStage(stage.getName())) {
        stages.push_back(stage);
    }
}

Stage* Project::getStageByName(const std::string& stageName) {

    for (Stage& stage : stages) {

        if (stage.getName() == stageName) {
            return &stage;
        }
    }

    return nullptr;
}

const Stage* Project::getStageByName(const std::string& stageName) const {

    for (const Stage& stage : stages) {

        if (stage.getName() == stageName) {
            return &stage;
        }
    }

    return nullptr;
}

bool Project::containsStage(const std::string& stageName) const {

    return getStageByName(stageName)
        != nullptr;
}

void Project::finalize() {
    status = ProjectStatus::Finished;
}

void Project::serialize(std::ostream& os) const {
    os << id << '\n';
    os << name << '\n';
    os << description << '\n';
    os << projectStatusToString(status) << '\n';

    os << memberIds.size() << '\n';
    for (unsigned int memberId : memberIds) {
        os << memberId << '\n';
    }

    os << taskIds.size() << '\n';
    for (unsigned int taskId : taskIds) {
        os << taskId << '\n';
    }

    os << stages.size() << '\n';
    for (const Stage& stage : stages) {
        stage.serialize(os);
    }
}

Project Project::deserialize(std::istream& is) {
    unsigned int id;
    std::string name;
    std::string description;
    std::string statusStr;

    is >> id;
    is.ignore();

    std::getline(is, name);
    std::getline(is, description);
    std::getline(is, statusStr);

    size_t memberCount;
    is >> memberCount;
    is.ignore();

    std::vector<unsigned int> memberIds;
    for (size_t i = 0; i < memberCount; i++) {
        unsigned int memberId;
        is >> memberId;
        is.ignore();
        memberIds.push_back(memberId);
    }

    size_t taskCount;
    is >> taskCount;
    is.ignore();

    std::vector<unsigned int> taskIds;
    for (size_t i = 0; i < taskCount; i++) {
        unsigned int taskId;
        is >> taskId;
        is.ignore();
        taskIds.push_back(taskId);
    }

    size_t stageCount;
    is >> stageCount;
    is.ignore();

    std::vector<Stage> stages;
    for (size_t i = 0; i < stageCount; i++) {
        stages.push_back(Stage::deserialize(is));
    }

    return Project(id, name, description, stringToProjectStatus(statusStr), memberIds, taskIds, stages);
}

void Project::print(std::ostream& os) const {
    os << "Project ID: " << id << '\n';
    os << "Name: " << name << '\n';
    os << "Description: " << description << '\n';
    os << "Status: "
        << projectStatusToString(status)
        << '\n';

    os << "Members: "
        << memberIds.size()
        << '\n';

    os << "Tasks: "
        << taskIds.size()
        << '\n';

    os << "Stages: "
        << stages.size()
        << '\n';
}

std::ostream& operator<<(std::ostream& os, const Project& project) {

    project.print(os);

    return os;
}