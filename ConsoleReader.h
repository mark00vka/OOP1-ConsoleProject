#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <string>

using namespace std;

class ConsoleReader {
public:
    static bool start();

protected:
    static void call_command(string line);

    static string read(string line);

    static char* check_syntax(string line);
};


#endif
