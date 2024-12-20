#include "fileHandler.h"
#include "constants.h"
#include <iostream>
#include <fstream>

void readFromFile(const std::string& fileName, std::string& content) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        setColor(RED_BG);
        std::cerr << "ERROR: Failed to open the  file: " << fileName << "\n";
        setColor(RESET_COLOR);
        exit(EXIT_FAILURE);
    }
    std::getline(inputFile, content, '\0');
    inputFile.close();
    std::cout << "Successfully read from : " << fileName << "\n";
}

void saveToFile(const std::string& sentence, const std::string& key, const std::string& operation, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        setColor(RED_BG);
        std::cerr << "ERROR: Failed to create the output file: " << outputFileName << "\n";
        setColor(RESET_COLOR);
        exit(EXIT_FAILURE);
    }
    outputFile << "Operation: " << operation << "\n";
    outputFile << "Sentence: " << sentence << "\n";
    outputFile << "Key: " << key << "\n";
    outputFile.close();
    std::cout << "Content saved successfully to :" << outputFileName << "\n";
}
