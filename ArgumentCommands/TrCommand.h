#ifndef TRCOMMAND_H
#define TRCOMMAND_H

#include "../AbstractClasses/ArgumentCommand.h"

class TrCommand : public ArgumentCommand{
public:
    TrCommand() {}

    virtual void parse_line(Parser* parser, string line);

    virtual string interpret(string line);

    virtual bool check_syntax();

    virtual string run();

    virtual string get_expected_format();

    virtual string get_command_name();

private:
    string what, with;
};

#endif