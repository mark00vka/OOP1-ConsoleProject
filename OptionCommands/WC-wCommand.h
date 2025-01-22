#ifndef WCwCOMMAND_H
#define WCwCOMMAND_H
#include "../AbstractClasses/Option.h"

class WCwCommand : public Option {
public:
    WCwCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
