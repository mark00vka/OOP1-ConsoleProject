#ifndef WCCOMMAND_H
#define WCCOMMAND_H
#include "../AbstractClasses/OptionCommand.h"

class WCCommand : public OptionCommand {
public:
    WCCommand();

    virtual string run() {return "";}

    virtual string get_command_name();
};


class WCwCommand : public Option {
public:
    WCwCommand() {}

    virtual string run();

    virtual string get_command_name();
};


class WCcCommand : public Option {
public:
    WCcCommand() {}

    virtual string run();

    virtual string get_command_name();
};

#endif
