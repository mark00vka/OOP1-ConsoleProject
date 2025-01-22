#include "OptionCommand.h"

string OptionCommand::get_expected_format(string command) {
    return "Expected format : " + command + " -option [argument]";
}
bool OptionCommand::check_syntax() {
    if (option == NONE_CONST) {
        write_to_console("Option expected in command " + get_command_name());
        write_to_console(get_expected_format("command"));
        return true;
    } if (argument == NONE_CONST) {
        write_to_console("Argument expected in command " + get_command_name());
        write_to_console(get_expected_format("command"));
        return true;
    }

    for (auto & var:options) {
        if (option == var->get_command_name()) {
            return false;
        }
    }
    write_to_console("No option " + option + " in command " + get_command_name() + ", try:");
    for (auto & var:options) {
        write_to_console(var->get_command_name());
    }
    return true;
}

void OptionCommand::interpret(string line) {
    parse_line(new Parser(), line);
    for (auto & var:options) {
        if (var->get_command_name() == option)
            var->interpret(line);
    }
}

OptionCommand::~OptionCommand() {
    for (Option *o: options)
        delete o;
}

