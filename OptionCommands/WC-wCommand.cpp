#include "WC-wCommand.h"

string WCwCommand::get_command_name() {
    return "-w";
}

void WCwCommand::run() {
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
    } else {
        write_to_file(to_string(count), output);
    }
}
