#ifndef UNTITLED_TIMECOMMAND_H
#define UNTITLED_TIMECOMMAND_H

#include "../AbstractClasses/Command.h"

class TimeCommand : Command {
public:
    TimeCommand() {}

    virtual string run();

    virtual string get_command_name();
};

#endif
