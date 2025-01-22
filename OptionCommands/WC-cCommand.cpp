#include "WC-cCommand.h"

string WCcCommand::get_command_name() {
    return "-c";
}

void WCcCommand::run() {

    int count = 0;
    for (int i = 0; argument[i] != '\0'; i++) {
            count++;
    }

    if (output == CONSOLE_CONST) {
        write_to_console(to_string(count));
    } else {
        write_to_file(to_string(count), output);
    }
}
