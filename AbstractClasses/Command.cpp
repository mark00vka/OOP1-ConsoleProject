#include "Command.h"

#include <utility>
void Command::parse_line(Parser* parser, string line){
    //skip command name
    int i = 0;
    for (; isspace(line[i]); i++) {}
    for (; !isspace(line[i]) && line[i] != '\0'; i++) {}
    if (line[i] == '\0') {
        option = NONE_CONST;
        argument = parser->parse_argument(line, &i);
        if (argument == ERROR_CONST) return;
        output = CONSOLE_CONST;
    }
    else {
        line = line.substr(i);
        i = 0;
        Parser::move_to_non_space(line, &i);

        option = parser->parse_option(line, &i);
        if (option == ERROR_CONST) return;
        Parser::move_to_non_space(line, &i);

        argument = parser->parse_argument(line, &i);
        if (argument == ERROR_CONST) return;
        Parser::move_to_non_space(line, &i);

        output = parser->parse_output(line, &i);
        if (output == ERROR_CONST) return;
    }
}

void Command::interpret(string line) {
    parse_line(new Parser(), std::move(line));
    if(check_syntax()) return;
    run();
}


string Command::get_expected_format(string command) {
    return "Expected format : " + command;
}

bool Command::check_syntax() {
    if (option != NONE_CONST) {
        write_to_console("No options in command");
        write_to_console(get_expected_format(get_command_name()));
        return true;
    } if (argument != NONE_CONST) {
        write_to_console("No arguments in command");
        write_to_console(get_expected_format(get_command_name()));
        return true;
    }
    return false;
}

Command::Command() = default;
