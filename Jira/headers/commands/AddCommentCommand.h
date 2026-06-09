#pragma once
#include "Command.h"

class AddCommentCommand : public Command {
public:
    explicit AddCommentCommand(const std::vector<std::string>& args);

    void execute(Context& context) override;
};