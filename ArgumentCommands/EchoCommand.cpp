#include "EchoCommand.h"
#include "../input_output.h"

void EchoCommand::run() {
    if (output == CONSOLE_CONST) {
        write_to_console(argument);
    } else {
        write_to_file(argument, output);
    }
}

string EchoCommand::get_command_name() {
    return "echo";
}
