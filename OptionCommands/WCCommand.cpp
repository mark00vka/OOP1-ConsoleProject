#include "WCCommand.h"

string WCCommand::get_command_name() {
    return "wc";
}

WCCommand::WCCommand() {
    options.push_back(new WCwCommand());
    options.push_back(new WCcCommand());
}

string WCwCommand::get_command_name() {
    return "-w";
}

string WCwCommand::run() {
    int i;
    int count = 0;
    for (i = 0; argument[i + 1] != '\0'; i++) {
        if (!isspace(argument[i]) && isspace(argument[i + 1])) {
            count++;
        }
    }
    if (!isspace(argument[i]))
        count++;

    if (output == CONSOLE_CONST) {
        write_to_console(to_string(count));
    } else if (output == PIPE_CONST) {
        return to_string(count);
    }else {
        write_to_file(to_string(count), output);
    }
    return NONE_CONST;
}

string WCcCommand::get_command_name() {
    return "-c";
}

string WCcCommand::run() {

    int count = 0;
    for (int i = 0; argument[i] != '\0'; i++) {
        count++;
    }

    if (output == CONSOLE_CONST) {
        write_to_console(to_string(count));
    } else if (output == PIPE_CONST) {
        return to_string(count);
    } else {
        write_to_file(to_string(count), output);
    }
    return NONE_CONST;
}
