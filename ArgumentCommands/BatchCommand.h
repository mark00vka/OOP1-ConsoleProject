#ifndef BATCHCOMMAND_H
#define BATCHCOMMAND_H
#include "../AbstractClasses/ArgumentCommand.h"

class BatchCommand : public ArgumentCommand {
public:
    BatchCommand() {}

    virtual string run();

    virtual string get_command_name();
};


#endif
