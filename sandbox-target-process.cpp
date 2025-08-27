// sandbox-target-process.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    char cmd;
    while (true) {
        std::cout << "[r]efresh  [g]enerate  [q]uit > ";
        std::cin >> cmd;

        if (cmd == 'q') break;
        else if (cmd == 'g') {
            //generateValues();
            //printValues();
        }
        else if (cmd == 'r') {
            //printValues();
        }
        else { std::cout << "Unrecognized command.\n"; }
    }
    return 0;
}