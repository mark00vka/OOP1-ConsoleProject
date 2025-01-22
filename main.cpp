#include <iostream>
#include "input_output.h"
#include "ConsoleReader.h"

using namespace std;

int main() {
    set_command_prompt("$");
    ConsoleReader::start();
    return 0;
}
