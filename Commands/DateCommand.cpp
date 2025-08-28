#include "DateCommand.h"
#include <ctime>

string DateCommand::run() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string result = to_string(now->tm_mday) + "." + to_string(now->tm_mon + 1) + "." + to_string(2000 + now->tm_year % 100) + ".";
    if (output == CONSOLE_CONST) {
        write_to_console(result);
    } else if (output == PIPE_CONST) {
        return result;
    } else {
        write_to_file(result, output);
    }
    return NONE_CONST;
}

string DateCommand::get_command_name() {
    return "date";
}
