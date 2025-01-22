#include "ArgumentCommand.h"

void ArgumentCommand::interpret(string line) {
    parse_line(new Parser(), line);

    if (argument == NONE_CONST)
        argument = read_arguments_console();
    if(check_syntax()) return;
    run();
}

string ArgumentCommand::get_expected_format(string command) {
    return "Expected format : " + command + " [argument]";
}

bool ArgumentCommand::check_syntax() {
    if (option != NONE_CONST) {
        write_to_console("No options in command " + get_command_name());
        write_to_console(get_expected_format(get_command_name()));
        return true;
    } if (argument == NONE_CONST) {
        write_to_console("Argument expected in command " + get_command_name());
        write_to_console(get_expected_format(get_command_name()));
        return true;
    }
    return false;
}
