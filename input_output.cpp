#include "input_output.h"

const int MAX_CONSOLE_LINE = 512;
const int MAX_STRING_SIZE = 512;

string prompt;

char* read_arguments_file(string filename) {
    ifstream file (filename);
    if (file.is_open()) {
        char* line = new char[MAX_STRING_SIZE];
        int n = 0 ;
        char c;
        while ((c = file.get()) != EOF) {
            line[n++] = c;
            if (n == MAX_STRING_SIZE - 1) {
                line[n] = '\0';
                return line;
            }
        }
        line[n] = '\0';
        return line;
    } else {
        write_to_console("File doesn't exist");
        return const_cast<char *>(ERROR_CONST.c_str());
    }
}

char* read_arguments_console() {
    char* line = new char[MAX_STRING_SIZE];
    int n = 0 ;
    char c;
    while ((c = getchar()) != EOF) {
        line[n++] = c;
        if (n == MAX_STRING_SIZE - 1) {
            line[n] = '\0';
            return line;
        }
    }
    line[n-1] = '\0';
    return line;
}

string read_console_line() {
    cout << prompt;
    char* line = new char[MAX_STRING_SIZE];
    int n = 0 ;
    char c;
    while ((c = getchar()) != '\n') {
        line[n++] = c;
        if (n == MAX_CONSOLE_LINE) {
            line[n] = '\0';
            return line;
        }
    }
    line[n] = '\0';
    string rez = string(line);
    delete[] line;
    return rez;
}

void write_to_console(string text) {
    cout << text << '\n';
}

void write_to_file(string text, string filename) {
    ofstream file (filename);
    file << text;
}

void set_command_prompt(string p) {
    prompt = p + " ";
}
