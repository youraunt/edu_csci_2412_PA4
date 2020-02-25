//
// Created by BK Allen on 2/21/20.
//

#include "functions.h"


/// @brief Handles user input with option of entering filename at command line
/// @param argc (argument count) the number of strings pointed to by argv should be 1+
/// @param argv (argument vector) A one dimensional array of strings. Each string is one
//   of the arguments passed to the program.
/// @param userInput string storage for user input
/// @param infile ifstream
/// @return userInput string
std::string getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile) {
    /// @brief I am a mac user and not familiar with command line prompts
    /// @brief I got this from a geeks for geeks post
    /// @todo TEST
    /// @brief if more than one argument is passed use it.
    if (argc > 1) { userInput = argv[1]; }
        /// else get input from user do/while to continue until valid file is found.
    else {
        do {// until file is found
            std::cout << "Please enter your file name: " << std::endl
                      << "\x1b[32m> \x1b[0m";
            std::cin >> userInput;
            //userInput = makeLowerCase(userInput);
            infile.open(userInput);
            if (!infile || infile.fail()) {
                std::cout << "I could not fine your file." << std::endl
                          << "Please, try again." << std::endl;
                continue;
            }
            break;
        } while (true);

    }///# else
    return std::string(userInput);
}///# getFileName

/// @brief functions to parse infile one string at a time
/// @brief each string is read in one char at a time
/// @param infile  ifstream reference
/// @return one string from the the
std::string getString(std::ifstream &infile) {
    assert(infile.is_open());
    std::string readIn;
    char tempChar;
    while (infile.peek() != EOF) {
        tempChar = infile.get();
        if (isalpha(tempChar) || isdigit(tempChar)) {
            readIn += tempChar;
        } else if (tempChar == ' ') { break; }
    }
    return readIn;
}


/// @brief This function builds a linked list from the filestream.
/// @param infile filestream
/// @return head node
node *linkedListBuilder(std::ifstream &infile) {
    auto *head = new node;
    auto lastNode = head;
    head->set_data(getString(infile));

    while (infile.peek() != EOF) {
        node *newNode = new node;
        lastNode->set_link(newNode);
        newNode->set_data(getString(infile));
        lastNode = newNode;
    }
    return head;
}///#linkedListBuilder

/// @brief This function handles user input.
/// @param userInput string to hold users input
/// @param searchNumber string to display which search this is.
/// @return  user input
std::string getSearch(std::string &userInput, const std::string &searchNumber) {
    std::cout << "\nWhat is the " << searchNumber << " word you would like to search for?" << std::endl
              << "\x1b[32m> \x1b[0m";
    std::cin >> userInput;
    return userInput;
}///#getSearch

/// @brief This function displays a linked list to the console
/// the for loops runs until last link
/// @param head const pointer to head node
void display(node *const head) {
    node *tempNode = head;
    for (; tempNode; tempNode = tempNode->link()) {
        std::cout << tempNode->data() << " ";
    }
}///#display

/// @brief This function checks to see if the user wants to
///     format the text to another width.
/// @return capitalized user input
bool loopProgram() {
    std::cout << "\nAnother sublist? (y/n)" << std::endl;
    std::cout << "\x1b[32m>\x1b[0m";
    std::string userInput;
    std::cin >> userInput;
    userInput = makeLowerCase(userInput);
    if (userInput == "y") {
        return true;
    } else return false;
}///#loopProgram

std::string makeLowerCase(const std::string &in) {
    std::string out;
    std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
    return out;
}///#makeLowerCase
/// @brief This function uses insertion sort to alphabetically sort a linked list
/// @param head  first node pointer reference
/// @authors I used a combination of the stl version and geeks for geeks version
void insertionSort(node *&head) {
    /// First index of list
    node *preSortHead = head->link();
    /// Current index of sorted list
    node *pointer = head;
    /// temporary housing for node pointers
    node *sublistHead = nullptr;
    node *sublist = nullptr;
    head->set_link(nullptr);

    do {/// until last node
        /// -- I conditioned that data to lowercase for comparison
        /// otherwise the capitalized words don't sort correctly
        while (makeLowerCase(preSortHead->data()) > makeLowerCase(pointer->data())) {
            if (pointer->link() == nullptr) {break;}
            else {// put node in sorted sublist and iterate
                sublist = pointer;
                pointer = pointer->link();
            }
        }///#while
        /// establish head of sublist for linkage and iterate
        sublistHead = preSortHead;
        preSortHead = preSortHead->link();
        sublistHead->set_link(pointer);
        /// if not front make front then link it all up
        if (sublist == nullptr) {
            head = sublistHead;
        } else { sublist->set_link(sublistHead); }
       /// set up for next iteration
        sublist = nullptr;
        pointer = head;
    } while (preSortHead != nullptr);

}///# insertion sort
