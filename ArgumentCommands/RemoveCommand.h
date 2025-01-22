#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class RemoveCommand : public ArgumentCommand {
public:
    RemoveCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
