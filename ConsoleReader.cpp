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


void ConsoleReader::call_command(string line) {
    vector<Command*> commands = { new EchoCommand(), new PromptCommand(), (Command*) new TimeCommand(),
                                  (Command*) new DateCommand(), new TouchCommand(), new TruncateCommand(),
                                  new RemoveCommand(), new WCCommand() };


    string cmd = ConsoleReader::read(line);
    if (cmd == ERROR_CONST) {
        for (auto &command: commands)
            delete command;
        return;
    }

    for(auto & command : commands) {
        if (command->get_command_name() == cmd) {
            command->interpret(line);
            for (auto &com: commands)
                delete com;
            return;
        }
    }
    write_to_console("Unknown command: " + string(cmd));
    for (auto &command: commands)
        delete command;
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
        } else if (line[i] == '.' || line[i] == '_' || in_commas || isalnum(line[i]) || line[i] == '-' ||
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
    for (i = 0; !isspace(line[i]) && line[i] != '\0'; i++) {}
    return line.substr(0, i);
}

bool ConsoleReader::start() {
    while (true) {
        call_command(read_console_line());
    }
}
