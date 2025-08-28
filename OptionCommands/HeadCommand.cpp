#include "HeadCommand.h"

string HeadCommand::get_command_name() {
    return "head";
}

string HeadCommand::get_expected_format() {
    return "Expected format : " + get_command_name() + " -ncount [argument]";
}

HeadCommand::HeadCommand() {
    options.push_back(new HeadNCommand());
}


string HeadNCommand::run() {
    try {
        int number_of_lines = stoi(option.substr(2));
        string result;
        int pointer = 0;
        for (int i = 0; i < number_of_lines; i++) {
            int new_pointer = argument.find('\n', pointer+1);
            if (new_pointer < pointer) {
                pointer = new_pointer;
                break;

            }
            pointer = new_pointer;
        }
        result = argument.substr(0, pointer);

        if (output == CONSOLE_CONST) {
            write_to_console(result);
        } else if (output == PIPE_CONST) {
            return result;
        } else {
            write_to_file(result, output);
        }
        return NONE_CONST;
    }
    catch(...) {
        write_to_console("Error - invalid option syntax");
        write_to_console(get_expected_format());
        return ERROR_CONST;
    }
}

string HeadNCommand::get_command_name() {
    return "-n";
}

bool HeadNCommand::is_form_correct(string form) {
    return form[0] == '-' && form[1] == 'n';
}

