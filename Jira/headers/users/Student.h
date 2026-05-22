#include "User.h"
#include <vector>
#include <string>

class Student : public User {
private:
    std::vector<unsigned int> joinedProjectIds;
    int completedTasksCount;
    int inProgressTasksCount;
    int performanceScore;

protected:
    void print(std::ostream& os) const override;

public:
    Student(const std::string& username,
        const std::string& password);

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

    void markTaskStarted();
    void markTaskCompleted(int taskPoints);

    int getCompletedTasksCount() const;
    int getInProgressTasksCount() const;
    int getPerformanceScore() const;

    void serialize(std::ostream& os) const override;

};