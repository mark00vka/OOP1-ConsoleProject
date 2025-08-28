#ifndef ARGUMENTCOMMAND_H
#define ARGUMENTCOMMAND_H
#include "Command.h"

class ArgumentCommand : public Command {
public:
    ArgumentCommand() = default;
    ~ArgumentCommand() override = default;

    virtual string interpret(string line);

    virtual string get_expected_format();

protected:

    virtual bool check_syntax();
};


#endif
