#pragma once
#include "User.h"
#include <vector>
#include <string>

class Student : public User {
private:
    std::vector<unsigned int> joinedProjectIds;
   
protected:
    void print(std::ostream& os) const override;

public:
    Student(const std::string& username,
        const std::string& password);

    Student(unsigned int id,
        const std::string& username,
        const std::string& password);

    //TODO: remove if needed
    Student(unsigned int id,
        const std::string& username,
        const std::string& password,
        int completed,
        int inProgress,
        int score);

    bool canCreateTask() const override;

    void joinProject(unsigned int projectId);

    bool isJoinedToProject(unsigned int projectId) const;

    const std::vector<unsigned int>& getJoinedProjectIds() const;


    
};