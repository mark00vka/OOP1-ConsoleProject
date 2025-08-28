#include "PromptCommand.h"
#include "../input_output.h"

string PromptCommand::run() {
    set_command_prompt(argument);
    return NONE_CONST;
}

string PromptCommand::get_command_name() {
    return "prompt";
}
