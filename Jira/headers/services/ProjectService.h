#pragma once
#include <string>

#include "../Context.h"
#include "../projects/Project.h"

class ProjectService {
public:
    static void createProject(Context& context,  const std::string& name, const std::string& description);

    static Project* findProjectByName(Context& context, const std::string& name);

    static Project* findProjectById(Context& context,  unsigned int id);

    static bool projectExists(Context& context, const std::string& name);

    static void addUserToProject(Context& context,const std::string& username, const std::string& projectName);

    static void archiveProject(Context& context, const std::string& projectName);

    static void finalizeProject(Context& context, const std::string& projectName);

    static Project* findProjectByTaskId(Context& context, unsigned int taskId);

    static void removeUser(Context& context, const std::string& username);

private:
    static void requireAdmin(Context& context);
    static void requireLecturer(Context& context);
};