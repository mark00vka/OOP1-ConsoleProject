#include "TouchCommand.h"
#include <fstream>

string TouchCommand::get_command_name() {
    return "touch";
}

string TouchCommand::run() {
    if (output != CONSOLE_CONST) {
        write_to_console("Error - No output source in command " + get_command_name());
        write_to_console(get_expected_format());
        return ERROR_CONST;
    }
    ifstream file (argument);
    if (file.is_open()) {
        write_to_console("Error - file " + argument + " exists");
        return ERROR_CONST;
    }
    ofstream f (argument);
    f.close();
    return NONE_CONST;
}

string TouchCommand::interpret(string line) {
    parse_line(new FilenameParser(), line);

    if (argument == NONE_CONST)
        argument = read_arguments_console();
    if(check_syntax()) return NONE_CONST;
    return run();
}
