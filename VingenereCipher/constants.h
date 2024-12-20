#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string RED_BG = "\033[30;41m";
const std::string GREEN_BG = "\033[30;42m";
const std::string YELLOW_BG = "\033[30;43m";
const std::string CYAN_BG = "\033[30;45m";
const std::string WHITE_BG = "\033[30;47m";
const std::string RESET_COLOR = "\033[0m";

enum class Mode { Encryption, Decryption };

void setColor(const std::string& colorCode);

#endif 
