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

    virtual string run() = 0;

    virtual string interpret(string line);

    void set_argument(string pipe_argument);

    void set_output_to_pipe();

    virtual string get_expected_format();

protected:

    virtual void parse_line(Parser* parser, string line);

    string option, argument, output;

    virtual bool check_syntax();
};


#endif
