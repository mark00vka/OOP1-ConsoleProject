#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "input_output.h"

using namespace std;

class Parser {
public:
    Parser() = default;

    static void move_to_non_space(string line, int* start) {
        for (; isspace(line[*start]); (*start)++) {}
    }

    virtual string parse_option(string line, int* start) {
        int i = *start;
        int j;
        if (line[i] == '-') {
            for (j = 1; !isspace(line[i + j]) && line[i+j] != '\0'; j++) {}
            if (j > 6) {
                write_to_console("Error - unexpected option format");
                return ERROR_CONST;
            }
            *start = i+j;
            return line.substr(i, j);
        }
        else
            return NONE_CONST;
    }

    virtual string parse_argument(string line, int* start) {
        int i = *start;
        int j;
        if (line[i] == '\0' || line[i] == '>' || line[i] == '\n') {
            return NONE_CONST;
        } else if (line[i] == '"') {
            for (j = i + 1; line[j] != '"'; j++) {
                if (line[j] == '\0') {
                    write_to_console("Error - no closing comma");
                    return ERROR_CONST;
                }
            }
            *start = j+1;
            return line.substr(i + 1, j - i - 1);
        } else {
            for (j = i; !isspace(line[j]) && line[j] != '\0'; j++) {}
            string argument = read_arguments_file(line.substr(i, j - i));
            *start = j;
            if (argument == ERROR_CONST) {
                return ERROR_CONST;
            }
            return argument;
        }
    }

    virtual string parse_output(string line, int* start) {
        int i = *start;
        int j;
        for (j = i; isspace(line[i]) && line[i] != '\0'; i++) {}
        if (line[j] == '>') {
            return line.substr(line.find('>') + 1, line.length() - i - 1);
        }
        else if (line[j] != '\0') {
            cout << line[j];
            write_to_console("Error - expected symbol > before a filename");
            return ERROR_CONST;
        } else
            return CONSOLE_CONST;
    }
};

class ParserFile : public Parser {
public:
    ParserFile() = default;

    string parse_argument(string line, int* start) override {
        int i = *start;
        int j;
        if (line[i] == '\0' || line[i] == '>' || line[i] == '\n') {
            *start = i;
            return NONE_CONST;
        } else if (line[i] == '"') {
            for (j = i + 1; line[j] != '"'; j++) {
                if (line[j] == '\0') {
                    write_to_console("Error - no closing comma");
                    return ERROR_CONST;
                }
            }
            *start = j+1;
            return line.substr(i + 1, j - i - 1);
        } else {
            for (j = i; !isspace(line[j]) && line[j] != '\0'; j++) {}
            *start = j;
            return line.substr(i, j - i);
        }
    }
};
#endif
