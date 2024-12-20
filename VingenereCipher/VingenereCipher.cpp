#include "constants.h"
#include "fileHandler.h"
#include "ui.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        showError("Insufficient arguments provided");
        return EXIT_FAILURE;
    }

    Mode currentMode = Mode::Encryption;
    std::string sentenceText;
    std::string keyText;
    std::string outputFileName;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h") {
            showHelp();
            return EXIT_SUCCESS;
        }
        else if (arg == "--en") {
            currentMode = Mode::Encryption;
        }
        else if (arg == "--de") {
            currentMode = Mode::Decryption;
        }
        else if (arg == "-i") {
            if (i + 1 < argc) {
                readFromFile(argv[++i], sentenceText);
            }
            else {
                showError("-i requires a file name");
                return EXIT_FAILURE;
            }
        }
        else if (arg == "-k") {
            if (i + 1 < argc) {
                readFromFile(argv[++i], keyText);
            }
            else {
                showError("-k requires a file name");
                return EXIT_FAILURE;
            }
        }
        else if (arg == "-o") {
            if (i + 1 < argc) {
                outputFileName = argv[++i];
            }
            else {
                showError("-o requires a file name");
                return EXIT_FAILURE;
            }
        }
        else {
            showError("Unknown argument: " + arg);
            return EXIT_FAILURE;
        }
    }

    if (sentenceText.empty() || keyText.empty() || outputFileName.empty()) {
        showError("Missing required inputs (-i, -k, -o)");
        return EXIT_FAILURE;
    }

    saveToFile(sentenceText, keyText, (currentMode == Mode::Encryption ? "Encryption" : "Decryption"), outputFileName);

    std::cout << "Operation completed successfully." << std::endl;
    return EXIT_SUCCESS;
}
