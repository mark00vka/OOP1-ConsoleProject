#ifndef WCcCOMMAND_H
#define WCcCOMMAND_H
#include "../AbstractClasses/OptionCommand.h"

class WCcCommand : public Option {
public:
    WCcCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
