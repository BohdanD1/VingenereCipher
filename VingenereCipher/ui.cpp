#include "ui.h"
#include <iostream>

void showHelp() {
    setColor(WHITE_BG);
    std::cout << "HELP MENU:\n";
    setColor(GREEN_BG);
    std::cout << "Usage: program_name [options]\n\n"
        << "Options:\n"
        << "  -h             Show this help menu\n"
        << "  --en           To start encryption process\n"
        << "  --de           To start decryption process\n"
        << "  -i <file>      To input file containing the sentence; folow the example: name.txt :\n"
        << "  -k <file>      To input file containing the key; folow the example: name.txt :\n"
        << "  -o <file>      To select file-name to create output file or use the existing file, to save the result; folow the example: name.txt :\n";
    setColor(RESET_COLOR);
}

void showError(const std::string& messageText) {
    setColor(RED_BG);
    std::cerr << "ERROR: " << messageText << "\n";
    setColor(YELLOW_BG);
    std::cerr << "Use -h for help\n";
    setColor(RESET_COLOR);
}
