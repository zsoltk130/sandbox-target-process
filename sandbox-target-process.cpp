#include <iostream>

// Helper functions
int randomInt() { return rand() % 100000; }
float randomFloat() { return (rand() % 10000) / 100.0f; }
double randomDouble() { return (rand() % 100000) / 100.0; }
std::string randomString() {
    int len = 1 + rand() % 5;
    std::string s;
    for (int i = 0; i < len; i++) {
        s += 'A' + (rand() % 26);
    }
    return s;
}

int main()
{
    srand((unsigned)time(nullptr));
    
    std::cout << randomInt() << std::endl;
    std::cout << randomFloat() << std::endl;
    std::cout << randomDouble() << std::endl;
    std::cout << randomString() << std::endl;

    char cmd;
    while (true) {
        std::cout << "[r]efresh  [g]enerate  [q]uit > ";
        std::cin >> cmd;

        if (cmd == 'q') break;
        else if (cmd == 'g') {

        }
        else if (cmd == 'r') {

        }
        else { std::cout << "Unrecognized command.\n"; }
    }
    return 0;
}