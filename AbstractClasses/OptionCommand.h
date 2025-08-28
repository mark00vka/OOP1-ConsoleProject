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

    virtual string run() = 0;

    virtual string get_command_name() = 0;

    virtual string interpret(string line);

    virtual string get_expected_format();

protected:
    vector<Option*> options;

    virtual bool check_syntax();
};


#endif
