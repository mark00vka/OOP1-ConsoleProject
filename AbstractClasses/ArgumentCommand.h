#ifndef ARGUMENTCOMMAND_H
#define ARGUMENTCOMMAND_H
#include "Command.h"

class ArgumentCommand : public Command {
public:
    ArgumentCommand() = default;
    ~ArgumentCommand() override = default;

    virtual void interpret(string line);

protected:

    virtual string get_expected_format(string command);

    virtual bool check_syntax();
};


#endif
