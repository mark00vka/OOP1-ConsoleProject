#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>
#include "../input_output.h"
#include "../Parser.h"

using namespace std;

class Command {
public:
    explicit Command();
    virtual ~Command() = default;

    virtual string get_command_name() = 0;

    virtual void run() = 0;

    virtual void interpret(string line);

protected:

    virtual void parse_line(Parser* parser, string line);

    string option, argument, output;

    virtual string get_expected_format(string command);

    virtual bool check_syntax();
};


#endif
