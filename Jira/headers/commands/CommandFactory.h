#include "Command.h"
#include "../../headers/commands/LoginCommand.h"
#include "../../headers/commands/RegisterCommand.h"
#include "../../headers/commands/LogoutCommand.h"

class CommandFactory {

public:

	static Command* generateCommand(std::string& cmdLine, std::vector<std::string>& tokens);
};