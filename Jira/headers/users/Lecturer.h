#pragma once
#include "User.h"

class Lecturer : public User {
protected:
    void print(std::ostream& os) const override;

public:
    Lecturer(const std::string& username,
        const std::string& password);

    Lecturer(unsigned int id,
        const std::string& username,
        const std::string& password);

    bool canApproveTask() const override;
    bool canReviewTask() const override;
    bool canChangePriority() const override;
    bool canManageStages() const override;

    bool canGradeTask() const override;

    bool canManageProjects() const override;
};