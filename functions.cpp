//
// Created by BK Allen on 2/21/20.
//

#include "functions.h"

using namespace hw4;


#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;


std::string hw4::functions::getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile) {
    /// @brief I am a mac user and not familiar with command line prompts
    /// @brief I got this from a geeks for geeks post
    /// @todo TEST
    if (argc > 1) {
        userInput = argv[1];
    }
    do {
        std::cout << "Please enter your file name: " << std::endl
                  << "\x1b[32m> \x1b[0m";
        std::cin >> userInput;
        /// @brief tolower returns the string in lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        infile.open(userInput);
        // assert(infile);
        // @brief This checks to for a working file stream.
        /// @brief Exits program if files stream is not working.
        if (!infile || infile.fail()) {
            std::cout << "I could not fine your file." << std::endl
                      << "Please, try again." << std::endl;
            continue;
        }
        break;
    } while (true);
    return std::string(userInput);
}

std::string hw4::functions::getString(std::ifstream &infile) {
    assert(infile.is_open());
    std::string readIn;
    char tempChar;
    while (infile.peek() != EOF) {
        tempChar = infile.get();
        if (isalpha(tempChar)) {
            //tolower(tempChar);
            readIn += tempChar;
        } else if (tempChar == ' ') { break; }
    }
    return readIn;
}


void hw4::functions::eat_white(std::ifstream &infile) {
    while (infile && isspace(infile.peek()))
        infile.ignore();
}

node *functions::linkedList(std::ifstream &infile) {
    auto *head = new node;
    auto lastNode = head;
    head->set_data(getString(infile));

    while (infile) {
        node *newNode = new node;
        lastNode->set_link(newNode);
        newNode->set_data(getString(infile));
        lastNode = newNode;
    }
    return head;
}
bool functions::isSearchValid(node *firstSearch) {
    return true;
}
/// @brief
/// @return
std::string functions::getSearch() {
    std::string userInput;
    std::string searchNumber = "1st";
    static bool called = false;
    if(called){
        searchNumber = "2nd";
    }
    called = true;

    std::cout << "\nWhat is the " << searchNumber << " word you would like to search for?" << std::endl
              << "\x1b[32m> \x1b[0m";
    std::cin.ignore().clear();
    getline(std::cin, userInput);
    return userInput;
}
/// @brief
/// @param head
void functions::printList(node *const head) {
    node * tempNode = head;
    for (; tempNode; tempNode = tempNode->link()) {
        std::cout<< tempNode->data() << " ";
    }
}


