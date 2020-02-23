#include <iostream>
#include "functions.h"
#include "node1.h"

using namespace hw4;

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

int main(int argc, char **argv) {
    node *linkedListHead = nullptr;
    node *subListHead = new node;
    node *subListTail = new node;
    node *search1 = new node;
    node *search2 = new node;

    try {
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief variable declaration
        std::string userInput;
        std::ifstream infile;
        userInput = functions::getFileName(argc, argv, userInput, infile);
        linkedListHead = functions::linkedList(infile);
        functions::printList(linkedListHead);
        search1 = list_search(linkedListHead, functions::getSearch());
        if(functions::isSearchValid(search1)) subListHead = search1;
        search2 = list_search(subListHead, functions::getSearch());
        if(functions::isSearchValid(search2)) subListTail = search2;
        WHAT_IS(subListHead)
        WHAT_IS(subListTail)


    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        functions::unknownInput();
    }

}///#main