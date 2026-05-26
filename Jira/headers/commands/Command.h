#pragma once
#include <vector>
#include <string>
#include "../Context.h"

class Command {
protected:
    std::vector<std::string> args;
public:
    explicit Command(const std::vector<std::string>& args) : args(args) {}

    virtual ~Command() = default;

    virtual void execute(Context& context) = 0;
};