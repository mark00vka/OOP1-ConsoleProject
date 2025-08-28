#include "ArgumentCommand.h"

string ArgumentCommand::interpret(string line) {
    parse_line(new Parser(), line);
    if (argument == NONE_CONST)
        argument = read_arguments_console();
    if(check_syntax()) return NONE_CONST;
    return run();
}

string ArgumentCommand::get_expected_format() {
    return "Expected format : " + get_command_name() + " [argument]";
}

bool ArgumentCommand::check_syntax() {
    if (option != NONE_CONST) {
        write_to_console("Error - No options in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    } if (argument == NONE_CONST) {
        write_to_console("Error - Argument expected in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    }
    return false;
}
