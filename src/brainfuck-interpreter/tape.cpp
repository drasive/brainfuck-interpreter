#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <sstream>
#include <sys/stat.h> 

#include "Tape.h"


using namespace std;

class Tape final {

    // Members
protected:
    unsigned int* cells_;
    unsigned int* activeCell_;

    // Getters/ Setters
public:
    unsigned int* getCells() {
        return cells_;
    }

    unsigned int getCellCount() {
        return sizeof(cells_) / sizeof(*cells_);
    }

    /**/
    unsigned int* getActiveCell() {
        return activeCell_;
    }

    // Constructors
public:
    Tape(unsigned int cells) {
        unsigned int maximum_tape_size = std::numeric_limits<unsigned int>::max();
        if (cells < 1 || cells > maximum_tape_size) {
            throw out_of_range("cells");
        }

        cells_ = new unsigned int[cells];
        activeCell_ = cells_;
    }

};
