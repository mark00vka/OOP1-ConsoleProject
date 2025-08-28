#include "EchoCommand.h"
#include "../input_output.h"

string EchoCommand::run() {
    if (output == CONSOLE_CONST) {
        write_to_console(argument);
    } else if (output == PIPE_CONST) {
        return argument;
    } else {
        write_to_file(argument, output);
    }
    return NONE_CONST;
}

string EchoCommand::get_command_name() {
    return "echo";
}
