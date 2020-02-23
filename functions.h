//
// Created by BK Allen on 2/21/20.
//

#ifndef INC_2188HW4_FUNCTIONS_H
#define INC_2188HW4_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include "node1.h"

using namespace main_savitch_5;
namespace hw4 {
    class functions {
    private:


    public:
//    /// @brief struct to define what a node looks like
//    struct node{
//        std::string data;
//        node *next;
//    };

        static std::string getFileName(int argc, char** argv, std::string &userInput, std::ifstream &infile);

        /// @brief Exits program successfully with message
        static inline std::string exitProgram() {
            std::cout << "Exiting program!" << std::endl;
            /// @brief I used EXIT_SUCCESS here to unwind the stack
            exit(EXIT_SUCCESS);
        }

        static inline void unknownInput() {
            std::cerr << "\nError?! Unknown input.\n" << std::endl;
            exitProgram();
        }

        [[noreturn]]static inline void fileNotFound() {
            std::cerr << "File not found!" << std::endl
                      << "Exiting Program!" << std::endl;
            /// @brief winds down stack
            exit(EXIT_FAILURE);
        }

        static void eat_white(std::ifstream &infile);

        static std::string getString(std::ifstream &infile);
        static node *linkedList(std::ifstream &infile);
        static std::string getSearch();
        static bool isSearchValid(node *firstearch);
        static void printList(node *const head);
    };

}

#endif //INC_2188HW4_FUNCTIONS_H
