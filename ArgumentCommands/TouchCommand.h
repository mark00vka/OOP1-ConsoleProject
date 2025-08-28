#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class TouchCommand : public ArgumentCommand {
public:
    TouchCommand() = default;

    string interpret(string line) override;

    virtual string run();

    virtual string get_command_name();
};


#endif
