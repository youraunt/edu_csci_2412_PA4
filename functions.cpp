//
// Created by BK Allen on 2/21/20.
//

#include "functions.h"


#define WHAT_IS(x) std::cerr << #x << " is " << x << std::endl;


std::string getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile) {
    /// @brief I am a mac user and not familiar with command line prompts
    /// @brief I got this from a geeks for geeks post
    /// @todo TEST
    if (argc > 1) { userInput = argv[1]; }
    do {
        std::cout << "Please enter your file name: " << std::endl
                  << "\x1b[32m> \x1b[0m";
        std::cin >> userInput;
        /// @brief tolower returns the string in lowercased
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

//
//    void eat_white(std::ifstream &infile) {
//        while (infile && isspace(infile.peek()))
//            infile.ignore();
//    }

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
}

bool isSearchValid(node *head, node *tosearch) {
    node *current = head;
    std::string data = tosearch->data();
    while (current != nullptr) {
        for (; current; current = current->link()) {
            std::string temp = current->data();
            if (temp == data) {
                std::cout << "Found a match!" << std::endl;
                return true;
            } else if (temp != data) std::cout << "Searching" << std::endl;
        }
    }
    std::cout << "No matches found!" << std::endl;
    return false;
}

/// @brief
/// @return
std::string getSearch(std::string &data, const std::string& searchNumber) {
    std::cout << "\nWhat is the " << searchNumber << " word you would like to search for?" << std::endl
              << "\x1b[32m> \x1b[0m";
    std::cin >> data;
    return data;
}

/// @brief
/// @param head
void display(node *const head) {
    node *tempNode = head;
    for (; tempNode; tempNode = tempNode->link()) {
        std::cout << tempNode->data() << " ";
    }
}


/// @brief This function checks to see if the user wants to
///     format the text to another width.
/// @return capitalized user input
bool loopProgram() {
    std::cout << "\nAnother width? (y/n)" << std::endl;
    std::cout << "\x1b[32m>\x1b[0m";
    char userInput;
    std::cin >> userInput;
    int userInputCap = toupper(userInput);
    if (userInputCap == 'Y')
        return true;
    else return false;
}///#loopProgram

std::string lowercased(const std::string &_string) {
    std::string temp;
    for (auto i : _string) {
        temp += tolower(i);
    }
    return temp;
}

void insertionSort(node* &head) {
    node* preSortHead = head->link();
    node* pointer = head;
    node* newSortedList = nullptr;
    node* sublist = nullptr;
    head->set_link(nullptr);

    while (preSortHead != nullptr) {
        while (lowercased(preSortHead->data()) > lowercased(pointer->data())) {
            if (pointer->link() == nullptr) {
                break;
            } else {
                sublist = pointer;
                pointer = pointer->link();
            }
        }
            newSortedList = preSortHead;
            preSortHead = preSortHead->link();
            newSortedList->set_link(pointer);
            if (sublist == nullptr) {
                head = newSortedList;
            } else { sublist->set_link(newSortedList); }
            sublist = nullptr;
            pointer = head;
        }

    }
