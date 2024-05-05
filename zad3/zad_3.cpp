#include <iostream>
#include <fstream>
#include <string>

void printHead(std::istream &input, int numLines) {
    std::string line;
    int linesPrinted = 0;
    
    while (linesPrinted < numLines && std::getline(input, line)) {
        std::cout << line << std::endl;
        linesPrinted++;
    }
}

int main(int argc, char *argv[]) {
    int numLines = 10;  // Default number of lines to print
    std::ifstream inputFile;
    
    if (argc < 2) {
        // No filename provided, read from standard input
        printHead(std::cin, numLines);
    } else {
        // Open the file for reading
        inputFile.open(argv[1]);
        if (!inputFile) {
            std::cerr << "Error opening file " << argv[1] << std::endl;
            return 1;
        }
        
        // Check if a specific number of lines is specified
        if (argc >= 3) {
            numLines = std::atoi(argv[2]);
        }
        
        // Print the first N lines from the file
        printHead(inputFile, numLines);
        
        // Close the file
        inputFile.close();
    }
    
    return 0;
}
