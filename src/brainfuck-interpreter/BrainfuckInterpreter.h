#pragma once

class BrainfuckInterpreter {

    // Members
private:
    long* tape_;
    long* tapeCell_;


    // Getters/ Setters
public:
    string getProgram();

    
    long* getTape();

    long getTapeSize();

    long* getTapeCell();


    // Constructors
public:
    BrainfuckInterpreter(string program, int tape_size = 10000);


    // Methods
public:
    void execute();

private:
    void buildInstructions();

    int getConsecutiveInstructionCount(string program, char instruction, int starting_index);


    // Instructions
private:
    void incrementCell(int amount = 1);

    void decrementCell(int amount = 1);


    void nextCell(int amount = 1);

    void previousCell(int amount = 1);


    void outputCell();

    void readInCell();

};
