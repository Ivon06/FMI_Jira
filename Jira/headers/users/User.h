#pragma once
#include <string>
#include "UserRole.hpp"
#include <ostream>

class User {

    unsigned int id;
    static unsigned int nextId;
    std::string username;
    std::string password;
    UserRole role;

protected:
    virtual void print(std::ostream& os) const;

public:
    User(const std::string& username, const std::string& password, UserRole role);

    User(unsigned int id, const std::string& username, const std::string& password, UserRole role);

    virtual ~User() = default;

    const unsigned int getId() const;
    const std::string getUsername() const;
    const UserRole getRole() const;

    
    bool checkPassword(const std::string& inputPassword) const;
    void changePassword(const std::string& oldPassword, const std::string& newPassword);

    virtual bool canCreateTask() const;
    virtual bool canApproveTask() const;
    virtual bool canReviewTask() const;
    virtual bool canChangePriority() const;
    virtual bool canManageStages() const;
    virtual bool canGradeTask() const;
    virtual bool canManageUsers() const;
    virtual bool canManageProjects() const;
    virtual bool canSaveLoadData() const;

    virtual void serialize(std::ostream& os) const;
    
    friend std::ostream& operator<<(std::ostream& os, const User& user); 

};
