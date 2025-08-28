#include "TruncateCommand.h"
#include <fstream>

string TruncateCommand::get_command_name() {
    return "truncate";
}

string TruncateCommand::run() {
    if (output != CONSOLE_CONST) {
        write_to_console("Error - No output source in command " + get_command_name());
        write_to_console(get_expected_format());
        return ERROR_CONST;
    }
    ofstream file (argument, ios::trunc);
    if (!file.is_open()) {
        write_to_console("Error - file " + argument + " doesn't exist");
        return ERROR_CONST;
    }
    return NONE_CONST;
}
