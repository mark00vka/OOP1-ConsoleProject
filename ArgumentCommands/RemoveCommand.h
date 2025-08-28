#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class RemoveCommand : public ArgumentCommand {
public:
    RemoveCommand() {}

    virtual string run();

    virtual string get_command_name();

    string interpret(string line);
};


#endif
