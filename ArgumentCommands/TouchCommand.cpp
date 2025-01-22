#include "TouchCommand.h"
#include <fstream>

string TouchCommand::get_command_name() {
    return "touch";
}

void TouchCommand::run() {
    if (output != CONSOLE_CONST) {
        write_to_console("No output source in command " + get_command_name());
        write_to_console(get_expected_format(get_command_name()));
        return;
    }
    ifstream file (argument);
    if (file.is_open()) {
        write_to_console("Error - file " + argument + " exists");
        return;
    }
    ofstream f (argument);
    f.close();
}

void TouchCommand::interpret(std::string line) {
    parse_line(new ParserFile(), line);

    if (argument == NONE_CONST)
        argument = read_arguments_console();
    if(check_syntax()) return;
    run();
}
