#ifndef optionCOMMAND_H
#define optionCOMMAND_H
#include <string>
#include "../input_output.h"
#include "ArgumentCommand.h"
#include "Option.h"

using namespace std;

class OptionCommand : public ArgumentCommand {
public:
    OptionCommand() = default;
    ~OptionCommand();

    virtual void run() {}

    virtual string get_command_name() = 0;

    virtual void interpret(string line);

protected:
    vector<Option*> options;

    virtual string get_expected_format(string command);

    virtual bool check_syntax();
};


#endif
