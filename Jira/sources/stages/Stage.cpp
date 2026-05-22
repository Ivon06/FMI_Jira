#include "../../headers/stages/Stage.h"
#include <algorithm>

std::string stageStatusToString(StageStatus status) {
    switch (status) {
    case StageStatus::Planned:
        return "Planned";
    case StageStatus::Active:
        return "Active";
    case StageStatus::Finished:
        return "Finished";
    default:
        return "Unknown";
    }
}

Stage::Stage(const std::string& name,
    std::time_t startDate,
    std::time_t endDate)
    : name(name),
    startDate(startDate),
    endDate(endDate),
    status(StageStatus::Planned) {
}

Stage::Stage(const std::string& name,
    std::time_t startDate,
    std::time_t endDate,
    StageStatus status)
    : name(name),
    startDate(startDate),
    endDate(endDate),
    status(status) {
}

const std::string& Stage::getName() const {
    return name;
}

std::time_t Stage::getStartDate() const {
    return startDate;
}

std::time_t Stage::getEndDate() const {
    return endDate;
}

StageStatus Stage::getStatus() const {
    return status;
}

const std::vector<unsigned int>& Stage::getTaskIds() const {
    return taskIds;
}

void Stage::start() {
    status = StageStatus::Active;
}

void Stage::finish() {
    status = StageStatus::Finished;
}

void Stage::addTask(unsigned int taskId) {
    if (!containsTask(taskId)) {
        taskIds.push_back(taskId);
    }
}

void Stage::removeTask(unsigned int taskId) {
    taskIds.erase(
        std::remove(taskIds.begin(), taskIds.end(), taskId),
        taskIds.end()
    );
}

bool Stage::containsTask(unsigned int taskId) const {
    return std::find(taskIds.begin(),
        taskIds.end(),
        taskId) != taskIds.end();
}

void Stage::serialize(std::ostream& os) const {
    os << name << '\n'
        << startDate << '\n'
        << endDate << '\n'
        << static_cast<int>(status) << '\n';

    os << taskIds.size() << '\n';

    for (unsigned int taskId : taskIds) {
        os << taskId << ' ';
    }

    os << '\n';
}

void Stage::print(std::ostream& os) const {
    os << "Stage: " << name << '\n'
        << "Start date: " << startDate << '\n'
        << "End date: " << endDate << '\n'
        << "Status: " << stageStatusToString(status) << '\n'
        << "Tasks count: " << taskIds.size() << '\n';
}

std::ostream& operator<<(std::ostream& os,
    const Stage& stage) {
    stage.print(os);
    return os;
}