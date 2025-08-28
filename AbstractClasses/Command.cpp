#include "Command.h"

#include <utility>
void Command::parse_line(Parser* parser, string line){
    //skip command name
    int i = 0;
    Parser::move_to_non_space(line, &i);

    for (; !isspace(line[i]) && line[i] != '\0' && line[i] != '|'; i++) {}
    if (line[i] == '\0' || line[i] == '|') {
        option = NONE_CONST;

        if (argument == NONE_CONST || argument == ERROR_CONST) {
            argument = parser->parse_argument(line, &i);
        }

        if (argument == ERROR_CONST) return;
        if (output != PIPE_CONST) output = CONSOLE_CONST;
    }
    else {
        line = line.substr(i);
        i = 0;
        Parser::move_to_non_space(line, &i);

        option = parser->parse_option(line, &i);
        if (option == ERROR_CONST) return;
        Parser::move_to_non_space(line, &i);

        if (argument == NONE_CONST || argument == ERROR_CONST) {
            argument = parser->parse_argument(line, &i);
            if (argument == ERROR_CONST) return;
            Parser::move_to_non_space(line, &i);
        }

        if (output != PIPE_CONST) {
            output = parser->parse_output(line, &i);
            if (output == ERROR_CONST) return;
        }
    }
}

string Command::interpret(string line) {
    parse_line(new Parser(), std::move(line));
    if(check_syntax()) return NONE_CONST;
    return run();
}


string Command::get_expected_format() {
    return "Expected format : " + get_command_name();
}

bool Command::check_syntax() {
    if (option != NONE_CONST) {
        write_to_console("Error - No options in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    } if (argument != NONE_CONST) {
        write_to_console("Error - No arguments in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    }
    return false;
}

void Command::set_argument(string pipe_argument) {
    argument = std::move(pipe_argument);
}

void Command::set_output_to_pipe() {
    output = PIPE_CONST;
}

Command::Command() = default;
