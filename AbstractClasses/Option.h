#ifndef VARIANT_H
#define VARIANT_H

#include "ArgumentCommand.h"

class Option : public ArgumentCommand{
public:

    Option() {}

    virtual string get_command_name() = 0;

    virtual bool is_form_correct(string form) { return form == get_command_name(); }

    void set_values(string opt, string arg, string out) {
        option = opt;
        argument = arg;
        output = out;
    }

protected:

    virtual bool check_syntax() {return false;}
};

#endif
