#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

enum class StageStatus {
    Planned,
    Active,
    Finished
};

std::string stageStatusToString(StageStatus status);

class Stage {
private:
    std::string name;
    std::time_t startDate;
    std::time_t endDate;
    std::vector<unsigned int> taskIds;
    StageStatus status;

    void print(std::ostream& os) const;

public:
    Stage(const std::string& name,
        std::time_t startDate,
        std::time_t endDate);

    Stage(const std::string& name,
        std::time_t startDate,
        std::time_t endDate,
        StageStatus status);

    const std::string& getName() const;
    std::time_t getStartDate() const;
    std::time_t getEndDate() const;
    StageStatus getStatus() const;
    const std::vector<unsigned int>& getTaskIds() const;

    void start();
    void finish();

    void addTask(unsigned int taskId);
    void removeTask(unsigned int taskId);
    bool containsTask(unsigned int taskId) const;

    void serialize(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os,
        const Stage& stage);
};