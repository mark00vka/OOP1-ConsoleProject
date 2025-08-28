#include "OptionCommand.h"

string OptionCommand::get_expected_format() {
    return "Expected format : " + get_command_name() + " -option [argument]";
}
bool OptionCommand::check_syntax() {
    if (option == NONE_CONST) {
        write_to_console("Error - Option expected in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    } if (argument == NONE_CONST) {
        write_to_console("Error - Argument expected in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    }

    for (auto & var:options) {
        if (option == var->get_command_name()) {
            return false;
        }
    }
    write_to_console("Error - No option " + option + " in command " + get_command_name() + ", try:");
    for (auto & var:options) {
        write_to_console(var->get_command_name());
    }
    return true;
}

string OptionCommand::interpret(string line) {
    parse_line(new Parser(), line);

    if (option == NONE_CONST) {
        write_to_console("Error - Option expected in command " + get_command_name());
        write_to_console(get_expected_format());
        return ERROR_CONST;

    } else if (option == ERROR_CONST) return ERROR_CONST;

    for (auto & var:options) {
        if (var->is_form_correct(option)){
            var->set_values(option, argument, output);
            return var->run();
        }
    }
    // No option found

    write_to_console("Error - No option " + option + " in command " + get_command_name() + ", try:");
    for (auto & var:options) {
        write_to_console(var->get_command_name());
    }
    return ERROR_CONST;
}

OptionCommand::~OptionCommand() {
    for (Option *o: options)
        delete o;
}

