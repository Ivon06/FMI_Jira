#pragma once
#include "User.h"
#include <vector>


class TeachingAssistant : public User {
private:
    std::vector<unsigned int> managedProjectIds;

protected:
    void print(std::ostream& os) const override;

public:
    TeachingAssistant(const std::string& username, const std::string& password);
    TeachingAssistant(unsigned int id, const std::string& username, const std::string& password);

    bool canApproveTask() const override;
    bool canReviewTask() const override;
    bool canChangePriority() const override;
    bool canManageStages() const override;
};