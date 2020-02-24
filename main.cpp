
#include "functions.h"
#include "node1.h"
#include <algorithm>

using namespace main_savitch_5;

#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;

int main(int argc, char **argv) {
    node* headPtr = nullptr;


    std::ifstream infile;

    try {
        // @brief Logical error on i/o operation
        ///        Fail() = true
        /// @param except, set to failbit, the error
        /// flag here, is a bitmask value of iostate
        std::cin.exceptions(std::istream::failbit);
        /// @brief variable declaration
        std::string userInput1;
        userInput1 = getFileName(argc, argv, userInput1, infile);
        headPtr = linkedListBuilder(infile);
        display(headPtr);
        bool again;

        do {
            node *search1 = nullptr;
            do {
                userInput1 = getSearch(userInput1, "first");
                search1 = list_search(headPtr, userInput1);
                if (search1 == nullptr) {
                    std::cout << "No matches in the linked list." << std::endl
                              << "Please try again." << std::endl;
                } else { std::cout << "I found a match!" << std::endl; }
            } while (search1 == nullptr);

            std::string userInput2;
            node *search2 = nullptr;
            do {
                userInput2 = getSearch(userInput2, "second");
                search2 = list_search(search1, userInput2);
                if (search2 == nullptr) {
                    std::cout << "search2 false" << std::endl
                              << "try again." << std::endl;
                } else { std::cout << "match" << std::endl; }
            } while (search2 == nullptr);

            node* subHeadPrt = new node;
            node* subTailPtr = new node;
            list_piece(search1, search2, subHeadPrt, subTailPtr);
            display(subHeadPrt);
            insertionSort(subHeadPrt);
            std::cout << "\nsorted\n" << std::endl;
            display(subHeadPrt);
            again = loopProgram();
        } while (again);

    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        unknownInput();
    }


}///#main