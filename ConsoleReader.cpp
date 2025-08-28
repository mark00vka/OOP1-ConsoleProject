#include "ConsoleReader.h"
#include "input_output.h"
#include "ArgumentCommands/EchoCommand.h"
#include "ArgumentCommands/PromptCommand.h"
#include "Commands/TimeCommand.h"
#include "Commands/DateCommand.h"
#include "ArgumentCommands/TouchCommand.h"
#include "ArgumentCommands/TruncateCommand.h"
#include "ArgumentCommands/RemoveCommand.h"
#include "OptionCommands/WCCommand.h"
#include "ArgumentCommands/TrCommand.h"
#include "OptionCommands/HeadCommand.h"


void ConsoleReader::start_pipe(string line) {
    vector<Command*> commands = { new EchoCommand(), new PromptCommand(), (Command*) new TimeCommand(),
                                  (Command*) new DateCommand(), new TouchCommand(), new TruncateCommand(),
                                  new RemoveCommand(), new WCCommand(), new TrCommand(), new HeadCommand()};

    int i = 0;
    int j = line.find('|', i) == -1 ? line.size() :  line.find('|', i);
    string prev_pipe_output = NONE_CONST;
    while (i < line.size()) {
        bool cmd_success = false;
        string cmd = ConsoleReader::read(line.substr(i, j-i));
        if (cmd != ERROR_CONST) {
            for (auto &command: commands) {
                if (command->get_command_name() == cmd) {
                    command->set_argument(prev_pipe_output);

                    if (j != line.size()) command->set_output_to_pipe();

                    prev_pipe_output = command->interpret(line.substr(i, j - i));
                    cmd_success = true;
                }
            }
            if (!cmd_success) write_to_console("Error - Unknown command: " + string(cmd));
        }

        i = j + 1;
        j = line.find('|', i) == -1 ? line.size() :  line.find('|', i);
    }
}

char *ConsoleReader::check_syntax(string line) {
    int err_count = 0;
    int i;
    bool in_commas = false;
    char* markers = new char[INT_MAX];
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"') {
            in_commas = !in_commas;
            markers[i] = ' ';
        } else if (line[i] == '/' || line[i] == '.' || line[i] == '_' || in_commas || isalnum(line[i]) || line[i] == '-' ||
                   line[i] == '>' || line[i] == '<' || line[i] == '|' || line[i] == '\t' || isspace(line[i])) {
            markers[i] = ' ';
        }
        else {
            markers[i] = '^';
            err_count++;
        }
    }
    markers[i] = '\0';
    if (err_count)
        return markers;

    return nullptr;
}

string ConsoleReader::read(string line) {
    char *check = check_syntax(line);
    if (check != nullptr) {
        write_to_console("Error - unexpected characters:");
        write_to_console(line);
        write_to_console(check);
        return ERROR_CONST;
    }
    //remove spaces before
    int i = 0;
    for (; isspace(line[i]); i++) {}
    line = line.substr(i);
    //read command name
    for (i = 0; !isspace(line[i]) && line[i] != '\0' && line[i] != '|'; i++) {}
    return line.substr(0, i);
}

bool ConsoleReader::start() {
    while (true) {
        start_pipe(read_console_line());
    }
}
