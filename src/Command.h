
#ifndef COMMAND_H
#define COMMAND_H
#include <string>

class Command {
public:
    Command(const std::string& name) : name(name) {}
    virtual void execute() = 0;
    virtual ~Command() = default;


public:
    std::string name;
private:
};

#endif // COMMAND_H