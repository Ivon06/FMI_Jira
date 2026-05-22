#include "..\..\headers\users\Student.h"

Student::Student(const std::string& username, const std::string& password)
	: User(username, password, UserRole::Student),
	completedTasksCount(0), inProgressTasksCount(0), performanceScore(0) {
}

Student::Student(unsigned int id,
    const std::string& username,
    const std::string& password)
    : User(id, username, password, UserRole::Student) {
}

Student::Student(unsigned int id, const std::string& username, const std::string& password,
	int completed, int inProgress, int score)
	: User(id, username, password, UserRole::Student),
	completedTasksCount(completed),
	inProgressTasksCount(inProgress),
	performanceScore(score) {
}

void Student::print(std::ostream& os) const {
    User::print(os);

    os << "Completed tasks: "
        << completedTasksCount << '\n';

    os << "In progress tasks: "
        << inProgressTasksCount << '\n';

    os << "Performance score: "
        << performanceScore << '\n';
}

bool Student::canCreateTask() const {
    return true;
}

void Student::joinProject(unsigned int projectId) {

    auto it = std::find(joinedProjectIds.begin(),
        joinedProjectIds.end(),
        projectId);

    if (it == joinedProjectIds.end()) {
        joinedProjectIds.push_back(projectId);
    }
}

bool Student::isJoinedToProject(unsigned int projectId) const {

    return std::find(joinedProjectIds.begin(),
        joinedProjectIds.end(),
        projectId)
        != joinedProjectIds.end();
}

const std::vector<unsigned int>&
Student::getJoinedProjectIds() const {

    return joinedProjectIds;
}

void Student::markTaskStarted() {
    ++inProgressTasksCount;
}

void Student::markTaskCompleted(int taskPoints) {

    if (taskPoints < 0) {
        throw std::invalid_argument("Negative task points.");
    }

    if (inProgressTasksCount > 0) {
        --inProgressTasksCount;
    }

    ++completedTasksCount;
    performanceScore += taskPoints;
}

int Student::getCompletedTasksCount() const {
    return completedTasksCount;
}

int Student::getInProgressTasksCount() const {
    return inProgressTasksCount;
}

int Student::getPerformanceScore() const {
    return performanceScore;
}

void Student::serialize(std::ostream& os) const {

    User::serialize(os);

    os << joinedProjectIds.size() << '\n';

    for (unsigned int id : joinedProjectIds) {
        os << id << ' ';
    }

    os << '\n';

    os << completedTasksCount << '\n'
        << inProgressTasksCount << '\n'
        << performanceScore << '\n';
}