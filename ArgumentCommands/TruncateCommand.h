#ifndef TRUNCATECOMMAND_H
#define TRUNCATECOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class TruncateCommand : public ArgumentCommand {
public:
    TruncateCommand() {}

    virtual void run();

    virtual string get_command_name();
};


#endif
