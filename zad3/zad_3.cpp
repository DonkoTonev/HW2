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
    int numLines = 10;
    std::ifstream inputFile;
    
    if (argc < 2) {
        printHead(std::cin, numLines);
    } else {
        inputFile.open(argv[1]);
        if (!inputFile) {
            std::cerr << "Error opening file " << argv[1] << std::endl;
            return 1;
        }
        
        if (argc >= 3) {
            numLines = std::atoi(argv[2]);
        }
        
        printHead(inputFile, numLines);
        
        inputFile.close();
    }
    
    return 0;
}
