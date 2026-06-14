#include "..\..\headers\users\Student.h"

Student::Student(const std::string& username, const std::string& password)
	: User(username, password, UserRole::Student) {
}

Student::Student(unsigned int id,
    const std::string& username,
    const std::string& password)
    : User(id, username, password, UserRole::Student) {
}

Student::Student(unsigned int id, const std::string& username, const std::string& password,
	int completed, int inProgress, int score)
	: User(id, username, password, UserRole::Student)
	{
}

void Student::print(std::ostream& os) const {
    User::print(os);

    
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



