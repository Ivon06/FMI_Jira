// Jira.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers/Context.h"
#include <string>
#include <exception>
#include "headers/commands/Command.h"
#include "headers/commands/CommandFactory.h"

int main()
{
    std::cout
        << "Welcome to FMI_Jira App."
        << std::endl;

    Context context;

    std::string commandLine;

    while (true) {

        std::cout << "> ";

        std::getline(std::cin, commandLine);

        if (commandLine.empty()) {
            continue;
        }

        if (commandLine == "exit") {

            std::cout
                << "Thank you for using FMI_Jira App!"
                << std::endl;

            break;
        }

        try {

            std::vector<std::string> tokens;

            Command* command =
                CommandFactory::generateCommand(
                    commandLine, tokens);

            if (!command) {

                std::cout
                    << "[Error] Unknown command."
                    << std::endl;

                continue;
            }

            command->execute(context);

            delete command;
        }
        catch (const std::exception& ex) {

            std::cout
                << "[Error] "
                << ex.what()
                << std::endl;
        }
    }

    return 0;
}


