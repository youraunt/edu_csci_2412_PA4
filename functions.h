//
// Created by BK Allen on 2/21/20.
//

#ifndef INC_2188HW4_FUNCTIONS_H
#define INC_2188HW4_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include "node1.h"

using namespace main_savitch_5;


std::string getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile);

/// @brief Exits program successfully with message
inline std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

inline void unknownInput() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    exitProgram();
}

[[noreturn]] inline void fileNotFound() {
    std::cerr << "File not found!" << std::endl
              << "Exiting Program!" << std::endl;
    /// @brief winds down stack
    exit(EXIT_FAILURE);
}
std::string lowercased(const std::string &_string);

void eat_white(std::ifstream &infile);

std::string getString(std::ifstream &infile);

node *linkedListBuilder(std::ifstream &infile);

std::string getSearch(std::string &data, const std::string& searchNumber);

bool isSearchValid(node *head, node *tosearch);

void display(node *const head);

void insertionSort(node *&head);

bool loopProgram();

#endif //INC_2188HW4_FUNCTIONS_H
