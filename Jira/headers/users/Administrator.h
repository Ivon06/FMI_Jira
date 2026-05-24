#pragma once
#include "User.h"

class Administrator : public User {
protected:
    void print(std::ostream& os) const override;

public:
    Administrator(const std::string& username,
        const std::string& password);

    Administrator(unsigned int id,
        const std::string& username,
        const std::string& password);

    bool canManageUsers() const override;
    bool canManageProjects() const override;
    bool canSaveLoadData() const override;
};