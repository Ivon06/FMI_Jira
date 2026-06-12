#include "Command.h"
#include "../../headers/commands/LoginCommand.h"
#include "../../headers/commands/RegisterCommand.h"
#include "../../headers/commands/LogoutCommand.h"
#include "../../headers/commands/CreateProjectCommand.h"
#include "../../headers/commands/AddUserToProjectCommand.h"
#include "../../headers/commands/AddStageCommand.h"
#include "../../headers/commands/StartStageCommand.h"
#include "../../headers/commands/FinishStageCommand.h"
#include "../../headers/commands/FinalizeProjectCommand.h"
#include "../../headers/commands/CreateTaskCommand.h"
#include "../../headers/commands/AssignTaskCommand.h"
#include "../../headers/commands/ChangeTaskStatusCommand.h"
#include "../../headers/commands/ChangeTaskPriorityCommand.h"
#include "../../headers/commands/GradeTaskCommand.h"
#include "../../headers/commands/AddCommentCommand.h"
#include "../../headers/commands/SaveCommand.h"
#include "../../headers/commands/LoadCommand.h"


class CommandFactory {

public:

	static Command* generateCommand(std::string& cmdLine, std::vector<std::string>& tokens);
};