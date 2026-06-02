#pragma once
#include <string>
#include <ctime>
#include "../../headers/Context.h"

class StageService {
public:
    static void addStage(Context& context, const std::string& projectName, const std::string& stageName, std::time_t startDate, std::time_t endDate);

    static void startStage(Context& context, const std::string& projectName, const std::string& stageName);

    static void finishStage(Context& context, const std::string& projectName, const std::string& stageName);

private:
    static void requireTeachingAssistantOrLecturer(Context& context);
};