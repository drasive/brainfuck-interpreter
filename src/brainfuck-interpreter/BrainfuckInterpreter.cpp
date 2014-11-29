#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <sstream>
#include <sys/stat.h> 

#include "BrainfuckInterpreter.h"


using namespace std;

void BrainfuckInterpreter::interpret(char program[]) {
    char *instruction_ptr = program;
    int memory[1000] = { 0 };
    int *memory_cell_ptr = memory;

    while (*instruction_ptr) {
        switch (*instruction_ptr) {
        case '+':
            (*memory_cell_ptr)++;
            break;
        case '-':
            (*memory_cell_ptr)--;
            break;
        case '>':
            memory_cell_ptr++;
            break;
        case '<':
            memory_cell_ptr--;
            break;
        case '.':
            cout << (char)*memory_cell_ptr;
            break;
        case ',':
            cin >> *memory_cell_ptr;
            cin.sync();
            break;
        case '[':
            if (*memory_cell_ptr == 0) {
                int bracket_count = 1;

                do {
                    instruction_ptr++;

                    if (*instruction_ptr == '[') bracket_count++;
                    else if (*instruction_ptr == ']') bracket_count--;
                } while (bracket_count != 0);
            }
            break;
        case ']':
            if (*memory_cell_ptr != 0) {
                int bracket_count = 1;

                do {
                    instruction_ptr--;

                    if (*instruction_ptr == ']') bracket_count++;
                    else if (*instruction_ptr == '[') bracket_count--;
                } while (bracket_count != 0);
            }
            break;
        }

        instruction_ptr++;
    }
}
