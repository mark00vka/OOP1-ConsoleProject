#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class TouchCommand : public ArgumentCommand {
public:
    TouchCommand() = default;

    void interpret(std::string line) override;

    virtual void run();

    virtual string get_command_name();
};


#endif
