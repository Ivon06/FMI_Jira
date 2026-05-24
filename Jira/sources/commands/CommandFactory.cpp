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

    if (commandName == "register") {
        return new RegisterCommand(tokens);
    }

    if (commandName == "logout") {
        return new LogoutCommand(tokens);
    }

    return nullptr;
}