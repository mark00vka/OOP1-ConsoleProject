#include "RemoveCommand.h"
#include <fstream>

string RemoveCommand::get_command_name() {
    return "rm";
}

string RemoveCommand::run() {
    if (std::remove(argument.c_str()) != 0) {
        write_to_console("Error - file " + argument + " doesn't exist");
        return ERROR_CONST;
    }
    if (output != CONSOLE_CONST && output != ERROR_CONST) {
        write_to_console("Error - No output source in command " + get_command_name());
        write_to_console(get_expected_format());
        return ERROR_CONST;
    }

    return NONE_CONST;
}

string RemoveCommand::interpret(string line) {
    parse_line(new FilenameParser(), line);

    if (argument == NONE_CONST)
        argument = read_arguments_console();
    if(check_syntax()) return NONE_CONST;
    return run();
}