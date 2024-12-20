#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

void readFromFile(const std::string& fileName, std::string& content);
void saveToFile(const std::string& sentence, const std::string& key, const std::string& operation, const std::string& outputFileName);

#endif
