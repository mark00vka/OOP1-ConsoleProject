#include "WC-cCommand.h"
#include "WC-wCommand.h"
#include "WCCommand.h"

string WCCommand::get_command_name() {
    return "wc";
}

WCCommand::WCCommand() {
    options.push_back(new WCwCommand());
    options.push_back(new WCcCommand());
}
