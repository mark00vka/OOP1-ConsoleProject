#include "RemoveCommand.h"
#include <fstream>

string RemoveCommand::get_command_name() {
    return "rm";
}

void RemoveCommand::run() {
    if (output != CONSOLE_CONST) {
        write_to_console("No output source in command " + get_command_name());
        write_to_console(get_expected_format(get_command_name()));
        return;
    }
    if (std::remove(argument.c_str()) != 0) {
        write_to_console("Error - file " + argument + " doesn't exist");
        return;
    }
}
