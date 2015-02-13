#pragma once

#include <string>


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


};
