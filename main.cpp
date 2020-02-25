/*******************************************************
*  Name         : Brice Allen
*  Student ID   : *****2188
*  Class        : CSC 2421
*  HW#          : 4
*  Due Date     : 11:59 PM Feb. 24, 2020
*  File Name    : 2188HW4
*******************************************************/
#include "functions.h"
#include "node1.h"
//#include <algorithm> My attempt at using the STL insertion sort fell short any hints?

using namespace main_savitch_5;

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

int main(int argc, char **argv) {
   /// @brief variables & file stream
    node* headPtr = nullptr;
    std::ifstream infile;
    std::ofstream outfile;

    try {
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief variable declaration to hold user Input for file name
        std::string userInput1;
        /// @brief call function to get file name
        userInput1 = getFileName(argc, argv, userInput1, infile);
        /// @brief set the headPtr to the first item in the file
        headPtr = linkedListBuilder(infile);
        /// @brief writes to console
        display(headPtr);
        /// variable to hold truth value in regards to whether or not the user wants to run the program again
        bool again;
        /// @brief do until user chooses to exit
        do {
            /// @brief declare a null node to hold the users word to search
            node *search1 = nullptr;
            do {// loop until a match is found pass user input and title of search in string
                userInput1 = getSearch(userInput1, "first");
                search1 = list_search(headPtr, userInput1);
                if (search1 == nullptr) {
                    std::cout << "No matches in the linked list." << std::endl
                              << "Please try again." << std::endl;
                } else { std::cout << "I found a match!" << std::endl; }
            } while (search1 == nullptr);
            std::string userInput2;
            node *search2 = nullptr;
            do {// loop until a match is found pass user input and title of search in string
                userInput2 = getSearch(userInput2, "second");
                search2 = list_search(search1, userInput2);
                if (search2 == nullptr) {
                    std::cout << "search2 false" << std::endl
                              << "try again." << std::endl;
                } else { std::cout << "match" << std::endl; }
            } while (search2 == nullptr);
            /// @brief sublist head and tail pointers
            node* subHeadPrt = new node;
            node* subTailPtr = new node;
            /// @brief see node1.h for documentation on provided funtcions
            list_piece(search1, search2, subHeadPrt, subTailPtr);
            std::cout << "\n\n\t\t\t\x1b[33m-----Unsorted sub list-----\x1b[0m\n" << std::endl;
            display(subHeadPrt);
            insertionSort(subHeadPrt);
            std::cout << "\n\n\t\t\t\x1b[33m-----Sorted sub list-----\x1b[0m\n" << std::endl;
            display(subHeadPrt);
            again = loopProgram();
        } while (again);

    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        unknownInput();
    }


}///#main