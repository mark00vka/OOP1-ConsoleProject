#ifndef DATECOMMAND_H
#define DATECOMMAND_H

#include "../AbstractClasses/Command.h"

class DateCommand : Command {
public:

    virtual void run();

    virtual string get_command_name();
};


#endif
