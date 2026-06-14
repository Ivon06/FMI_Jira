#include "../../headers/commands/CommandFactory.h"

#include <algorithm>
#include <vector>

static void trimExtraSpaces(std::string& str) {
	while (!str.empty() && str.front() == ' ') {
		str.erase(str.begin());
	}

	while (!str.empty() && str.back() == ' ') {
		str.pop_back();
	}
}

std::vector<std::string> splitBySpaces(const std::string& str) {
	std::vector<std::string> result;
	std::string current;

	for (char ch : str) {
		if (ch == ' ') {
			if (!current.empty()) {
				result.push_back(current);
				current.clear();
			}
		}
		else {
			current += ch;
		}
	}

	if (!current.empty()) {
		result.push_back(current);
	}

	return result;
}

Command* CommandFactory::generateCommand(std::string& cmdLine, std::vector<std::string>& tokens) {
	trimExtraSpaces(cmdLine);

	tokens = splitBySpaces(cmdLine);

	if (tokens.empty()) {
		return nullptr;
	}

	std::string commandName = tokens[0];

	std::transform(commandName.begin(),
		commandName.end(),
		commandName.begin(),
		::tolower);

	tokens.erase(tokens.begin());

	if (commandName == "login") {
		return new LoginCommand(tokens);
	}
	else if (commandName == "register") {
		return new RegisterCommand(tokens);
	}
	else if (commandName == "logout") {
		return new LogoutCommand(tokens);
	}
	else if (commandName == "create-project") {
		return new CreateProjectCommand(tokens);
	}
	else if (commandName == "add-user-to-project") {
		return new AddUserToProjectCommand(tokens);
	}
	else if (commandName == "add-stage") {
		return new AddStageCommand(tokens);
	}
	else if (commandName == "start-stage") {
		return new StartStageCommand(tokens);
	}
	else if (commandName == "finish-stage") {
		return new FinishStageCommand(tokens);
	}
	else if (commandName == "finalize-project") {
		return new FinalizeProjectCommand(tokens);
	}
	else if (commandName == "create-task") {
		return new CreateTaskCommand(tokens);
	}
	else if (commandName == "assign-task") {
		return new AssignTaskCommand(tokens);
	}
	else if (commandName == "change-task-status") {
		return new ChangeTaskStatusCommand(tokens);
	}
	else if (commandName == "change-task-priority") {
		return new ChangeTaskPriorityCommand(tokens);
	}
	else if (commandName == "grade-task") {
		return new GradeTaskCommand(tokens);
	}
	else if (commandName == "add-comment") {
		return new AddCommentCommand(tokens);
	}
	else if (commandName == "save") {
		return new SaveCommand(tokens);
	}
	else if (commandName == "load") {
		return new LoadCommand(tokens);
	}
	else if (commandName == "move-task-to-stage") {
		return new MoveTaskToStageCommand(tokens);
	}
	else if (commandName == "view-profile") {
		return new ViewProfileCommand(tokens);
	}
	else if (commandName == "list-projects") {
		return new ListProjectsCommand(tokens);
	}
	else if (commandName == "view-project") {
		return new ViewProjectCommand(tokens);
	}
	else if (commandName == "view-task") {
		return new ViewTaskCommand(tokens);
	}
	else if (commandName == "my-tasks") {
		return new MyTasksCommand(tokens);
	}


	return nullptr;
}