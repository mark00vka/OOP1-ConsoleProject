#ifndef ECHOCOMMAND_H
#define ECHOCOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class EchoCommand : public ArgumentCommand {
public:
    EchoCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
