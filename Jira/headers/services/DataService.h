#pragma once
#include "../Context.h"
#include <string>

class DataService {
public:
    static void save(Context& context);
    static void load(Context& context);

private:
    static void saveUsers(Context& context, const std::string& filename);
    static void saveProjects(Context& context, const std::string& filename);
    static void saveTasks(Context& context, const std::string& filename);

    static void loadUsers(Context& context, const std::string& filename);
    static void loadProjects(Context& context, const std::string& filename);
    static void loadTasks(Context& context, const std::string& filename);

    static bool fileExists(const std::string& filename);
    static void seedAdmin(Context& context);
};