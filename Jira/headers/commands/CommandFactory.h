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

class CommandFactory {

public:

	static Command* generateCommand(std::string& cmdLine, std::vector<std::string>& tokens);
};