#ifndef CONSOLE_READ_H
#define CONSOLE_READ_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string CONSOLE_CONST = "__CONSOLE__CONST";
const string ERROR_CONST = "__ERROR__CONST";
const string NONE_CONST = "__NONE__CONST";

void set_command_prompt(string p);

char* read_arguments_file(string filename);

char* read_arguments_console();

string read_console_line();

void write_to_console(string text);

void write_to_file(string text, string filename);

#endif
