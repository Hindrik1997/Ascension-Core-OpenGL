//
// Created by hindrik on 21-1-17.
//

#ifndef ASCENSION_CORE_CONSOLE_H
#define ASCENSION_CORE_CONSOLE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Console {
public:

    static void printLine(string input);
    static void print(string input);



};

inline void Console::printLine(string input) {
    cout << input << endl;
}

inline void Console::print(string input) {
    cout << input;
}

#endif //ASCENSION_CORE_CONSOLE_H
