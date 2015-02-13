#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <sstream>
#include <sys/stat.h> 

#include "BrainfuckInterpreter.h"

#define BRAINFUCK_TOKEN_INCREMENT_CELL '+'
#define BRAINFUCK_TOKEN_DECREMENT_CELL '-'
#define BRAINFUCK_TOKEN_NEXT_CELL '>'
#define BRAINFUCK_TOKEN_PREVIOUS_CELL '<'
#define BRAINFUCK_TOKEN_OUTPUT '.'
#define BRAINFUCK_TOKEN_INPUT ','
#define BRAINFUCK_TOKEN_LOOP_START '['
#define BRAINFUCK_TOKEN_LOOP_END ']'


using namespace std;

class BrainfuckInterpreter final {

    // Members
protected:
    string program_;

    bool  built_instructions_;
    char* instructions_;

    long* tape_;
    long* tapeCell_;

    // Getters/ Setters
public:
    string getProgram() {
        return program_;
    }


    long* getTape() {
        return tape_;
    }

    long getTapeSize() {
        return sizeof(tape_) / sizeof(*tape_);
    }

    long* getTapeCell() {
        return tapeCell_;
    }

    // Constructors
public:
    BrainfuckInterpreter(string program, int tape_size = 10000) {
        // Validate parameters
        long maximum_array_size = std::numeric_limits<long>::max();
        if (tape_size < 1 || tape_size > maximum_array_size) {
            throw out_of_range("tape_size");
        }

        // Setup tape
        tape_ = new long[tape_size];
        tapeCell_ = tape_;
    }


    // Methods
public:
    void execute() {
        if (!built_instructions_) {
            buildInstructions(program_);
        }

        //Instruction *instruction_ptr = instructions;
        //
        //while (*instruction_ptr) {
        //    switch (*instruction_ptr.instruction) {
        //    case '+':
        //        (*memory_cell_ptr)++;
        //        break;
        //    case '-':
        //        (*memory_cell_ptr)--;
        //        break;
        //    case '>':
        //        memory_cell_ptr++;
        //        break;
        //    case '<':
        //        memory_cell_ptr--;
        //        break;
        //    case '.':
        //        cout << (char)*memory_cell_ptr;
        //        break;
        //    case ',':
        //        cin >> *memory_cell_ptr;
        //        cin.sync();
        //        break;
        //    case '[':
        //        if (*memory_cell_ptr == 0) {
        //            int bracket_count = 1;
        //
        //            do {
        //                instruction_ptr++;
        //
        //                if (*instruction_ptr == '[') bracket_count++;
        //                else if (*instruction_ptr == ']') bracket_count--;
        //            } while (bracket_count != 0);
        //        }
        //        break;
        //    case ']':
        //        if (*memory_cell_ptr != 0) {
        //            int bracket_count = 1;
        //
        //            do {
        //                instruction_ptr--;
        //
        //                if (*instruction_ptr == ']') bracket_count++;
        //                else if (*instruction_ptr == '[') bracket_count--;
        //            } while (bracket_count != 0);
        //        }
        //        break;
        //    }
        //
        //    instruction_ptr++;
        //}
    }

private:
    void buildInstructions(string program) {
        for (int character_index = 0; character_index < program.size(); character_index++) {
            char current_character = program[character_index];
            switch (current_character) {
            case BRAINFUCK_TOKEN_INCREMENT_CELL:
                // TODO: __Fill a list with function pointers to the instructions
                int consecutive_instruction_count = getConsecutiveInstructionCount(program, BRAINFUCK_TOKEN_INCREMENT_CELL, character_index++);


                break;
            case BRAINFUCK_TOKEN_DECREMENT_CELL:

                break;
            case BRAINFUCK_TOKEN_NEXT_CELL:

                break;
            case BRAINFUCK_TOKEN_PREVIOUS_CELL:

                break;
            case BRAINFUCK_TOKEN_OUTPUT:

                break;
            case BRAINFUCK_TOKEN_INPUT:

                break;
            case BRAINFUCK_TOKEN_LOOP_START:

                break;
            case BRAINFUCK_TOKEN_LOOP_END:

                break;
            }
        }
    }

    int getConsecutiveInstructionCount(string program, char instruction, int starting_index) {
        int consecutive_instruction_count = 0;

        for (int character_index = starting_index; character_index < program_.size(); character_index++) {
            char current_character = program[character_index];
            while (current_character == instruction) {
                consecutive_instruction_count++;
            }
        }

        return consecutive_instruction_count;
    }

    // Instructions
private:
    void incrementCell(int amount = 1) {
        (*tapeCell_) += amount;
    }

    void decrementCell(int amount = 1) {
        (*tapeCell_) -= amount;
    }


    void nextCell(int amount = 1) {
        tapeCell_ += amount;
    }

    void previousCell(int amount = 1) {
        tapeCell_ -= amount;
    }


    void outputCell() {
        cout << (char)*tapeCell_;
    }

    void readInCell() {
        cin >> *tapeCell_;
        cin.sync();
    }

};
