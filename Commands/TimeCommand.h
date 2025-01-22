#ifndef UNTITLED_TIMECOMMAND_H
#define UNTITLED_TIMECOMMAND_H

#include "../AbstractClasses/Command.h"

class TimeCommand : Command {
public:
    TimeCommand() {}

    virtual void run();

    virtual string get_command_name();
};

#endif
