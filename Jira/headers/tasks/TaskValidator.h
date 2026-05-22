#include <string>
#include <ctime>


class TaskValidator {
public:
    static void validateTitle(
        const std::string& title);

    static void validatePoints(
        int points);

    static void validateGrade(
        double grade);

    static void validateDeadline(
        std::time_t deadline);
};