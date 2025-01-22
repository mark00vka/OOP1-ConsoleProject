#include "DateCommand.h"
#include <ctime>

void DateCommand::run() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    if (output == CONSOLE_CONST) {
        write_to_console(to_string(now->tm_mday) + "." + to_string(now->tm_mon + 1) + "." + to_string(2000 + now->tm_year % 100) + ".");
    } else {
        write_to_file(to_string(now->tm_mday) + "." + to_string(now->tm_mon + 1) + "." + to_string(2000 + now->tm_year % 100) + ".", output);
    }
}

string DateCommand::get_command_name() {
    return "date";
}
