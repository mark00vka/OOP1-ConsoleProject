#ifndef HEADCOMMAND_H
#define HEADCOMMAND_H
#include "../AbstractClasses/OptionCommand.h"

class HeadCommand : public OptionCommand {
public:
    HeadCommand();

    virtual string run() {return "";}

    virtual string get_command_name();

    virtual string get_expected_format();
};


class HeadNCommand : public Option {
public:

    HeadNCommand() = default;

    virtual string run();

    virtual string get_command_name();

    virtual bool is_form_correct(string form);
};

#endif
