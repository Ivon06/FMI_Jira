#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../stages/Stage.h"

enum class ProjectStatus {
    Active,
    Finished
};

std::string projectStatusToString(
    ProjectStatus status);

class Project {
private:
    static unsigned int nextId;

    unsigned int id;

    std::string name;
    std::string description;

    std::vector<unsigned int> memberIds;
    std::vector<unsigned int> taskIds;

    std::vector<Stage> stages;

    ProjectStatus status;

    void print(std::ostream& os) const;

public:
    Project(const std::string& name,
        const std::string& description);

    Project(unsigned int id,
        const std::string& name,
        const std::string& description,
        ProjectStatus status);

    unsigned int getId() const;

    const std::string& getName() const;

    const std::string& getDescription() const;

    ProjectStatus getStatus() const;

    const std::vector<unsigned int>&
        getMemberIds() const;

    const std::vector<unsigned int>&
        getTaskIds() const;

    const std::vector<Stage>&
        getStages() const;

    void addMember(unsigned int userId);

    void removeMember(unsigned int userId);

    bool containsMember(unsigned int userId) const;

    void addTask(unsigned int taskId);

    bool containsTask(unsigned int taskId) const;

    void addStage(const Stage& stage);

    Stage* getStageByName(
        const std::string& stageName);

    const Stage* getStageByName(
        const std::string& stageName) const;

    bool containsStage(
        const std::string& stageName) const;

    void finalize();

    void serialize(std::ostream& os) const;

    friend std::ostream& operator<<(
        std::ostream& os,
        const Project& project);
};