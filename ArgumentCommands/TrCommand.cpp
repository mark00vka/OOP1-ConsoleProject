#include "TrCommand.h"

void TrCommand::parse_line(Parser* parser, string line){
    //skip command name
    int i = 0;
    Parser::move_to_non_space(line, &i);

    for (; !isspace(line[i]) && line[i] != '\0' && line[i] != '|'; i++) {}
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

        if (argument.empty()) {
            argument = parser->parse_argument(line, &i);
            if (argument == ERROR_CONST) return;
            Parser::move_to_non_space(line, &i);
        }

        what = parser->parse_argument(line, &i);
        if (what == ERROR_CONST) return;
        Parser::move_to_non_space(line, &i);

        with = parser->parse_argument(line, &i);
        if (with == ERROR_CONST) return;
        Parser::move_to_non_space(line, &i);

        if (output.empty()) {
            output = parser->parse_output(line, &i);
            if (output == ERROR_CONST) return;
        }
    }
}

string TrCommand::interpret(string line) {
    parse_line(new Parser(), std::move(line));
    if(check_syntax()) return NONE_CONST;
    return run();
}

bool TrCommand::check_syntax() {
    if (option != NONE_CONST) {
        write_to_console("Error - No options in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    } if (what == NONE_CONST) {
        write_to_console("Error - \"what\" expected in command " + get_command_name());
        write_to_console(get_expected_format());
        return true;
    }
    return false;
}

string TrCommand::get_expected_format() {
    return "Expected format : " + get_command_name() + " [argument] what [with]";
}

string TrCommand::get_command_name() {
    return "tr";
}

string TrCommand::run() {
    string result;
    int i = 0;
    int j = argument.find(what, i);

    while (j != -1) {
        result += argument.substr(i, j-i) + ((with == NONE_CONST) ? "" : with);
        i = j + what.size();
        j = argument.find(what, i);
    }
    result += argument.substr(i, argument.size() - 1);

    if (output == CONSOLE_CONST) {
        write_to_console(result);
    } else if (output == PIPE_CONST) {
        return result;
    } else {
            write_to_file(result, output);
    }
    return NONE_CONST;
}
