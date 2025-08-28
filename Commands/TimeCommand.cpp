#include "TimeCommand.h"
#include <ctime>

using namespace std;

string TimeCommand::run() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    string time = to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
    if (output == CONSOLE_CONST) {
        write_to_console(time);
    } else if (output == PIPE_CONST) {
        return time;
    } else {
        write_to_file(time, output);
    }
    return NONE_CONST;
}

string TimeCommand::get_command_name() {
    return "time";
}
