#include "..\..\headers\users\TeachingAssistant.h"

TeachingAssistant::TeachingAssistant(const std::string& username, const std::string& password)
    : User(username, password, UserRole::TeachingAssistant) {
}

TeachingAssistant::TeachingAssistant(unsigned int id, const std::string& username, const std::string& password)
    : User(id, username, password, UserRole::TeachingAssistant) {
}

void TeachingAssistant::print(std::ostream& os) const {
    User::print(os);
}

bool TeachingAssistant::canApproveTask() const {
    return true;
}

bool TeachingAssistant::canReviewTask() const {
    return true;
}

bool TeachingAssistant::canChangePriority() const {
    return true;
}

bool TeachingAssistant::canManageStages() const {
    return true;
}