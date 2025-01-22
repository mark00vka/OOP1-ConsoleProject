#ifndef PROMPTCOMMAND_H
#define PROMPTCOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class PromptCommand : public ArgumentCommand {
public:
    PromptCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
