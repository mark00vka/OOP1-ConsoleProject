#ifndef WCCOMMAND_H
#define WCCOMMAND_H
#include "../AbstractClasses/OptionCommand.h"

class WCCommand : public OptionCommand {
public:
    WCCommand();


    virtual string get_command_name();
};


#endif
