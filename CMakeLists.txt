cmake_minimum_required(VERSION 3.27)
project(OOP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP1 main.cpp
        ConsoleReader.cpp
        input_output.cpp
        OptionCommands/WCCommand.cpp
        OptionCommands/WC-cCommand.cpp
        "AbstractClasses/OptionCommand.cpp"
        ArgumentCommands/TruncateCommand.cpp
        ArgumentCommands/TouchCommand.cpp
        Commands/TimeCommand.cpp
        ArgumentCommands/RemoveCommand.cpp
        ArgumentCommands/PromptCommand.cpp
        ArgumentCommands/EchoCommand.cpp
        Commands/DateCommand.cpp
        "AbstractClasses/Command.cpp"
        "AbstractClasses/ArgumentCommand.cpp"
        OptionCommands/WC-wCommand.cpp
        "AbstractClasses/Option.h"
        Parser.h)
