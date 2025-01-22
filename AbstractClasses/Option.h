#ifndef VARIANT_H
#define VARIANT_H

#include "ArgumentCommand.h"

class Option : public ArgumentCommand{
public:

    Option() {}

    virtual string get_command_name() = 0;
protected:

    virtual bool check_syntax() {return false;}
};

#endif
