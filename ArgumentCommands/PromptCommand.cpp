#include "PromptCommand.h"
#include "../input_output.h"

void PromptCommand::run() {
    set_command_prompt(argument);
}

string PromptCommand::get_command_name() {
    return "prompt";
}
