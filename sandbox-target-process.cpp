#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct TestVar {
    std::string type;
    void* address;
    std::string valueStr; // Printable form
};

// Global test variables
int gInt;
float gFloat;
double gDouble;
char gString[6]; // Up to 5 chars + null terminator

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

void generateValues() {
    gInt = randomInt();
    gFloat = randomFloat();
    gDouble = randomDouble();
    std::string s = randomString();
    strncpy_s(gString, s.c_str(), sizeof(gString));
    gString[sizeof(gString) - 1] = '\0';
}

// Get variable details
std::vector<TestVar> collectInfo() {
    std::vector<TestVar> vars;
    vars.push_back({ "Integer", &gInt, std::to_string(gInt) });
    vars.push_back({ "Float", &gFloat, std::to_string(gFloat) });
    vars.push_back({ "Double", &gDouble, std::to_string(gDouble) });
    vars.push_back({ "String", gString, std::string(gString) });
    return vars;
}

void printValues() {
    auto vars = collectInfo();
    for (auto& v : vars) {
        std::cout << std::left << std::setw(8) << v.type
            << " | Address: 0x" << std::hex << (uintptr_t)v.address
            << std::dec << " | Value: " << v.valueStr << "\n";
    }
    std::cout << "--------------------------------------------\n";
}

int main()
{
    srand((unsigned)time(nullptr));

    generateValues();
    printValues();
    
    char cmd;
    while (true) {
        std::cout << "[r]efresh  [g]enerate  [q]uit > ";
        std::cin >> cmd;

        if (cmd == 'q') break;
        else if (cmd == 'g') {
            generateValues();
            printValues();
        }
        else if (cmd == 'r') {
            printValues();
        }
        else { std::cout << "Unrecognized command.\n"; }
    }
    return 0;
}