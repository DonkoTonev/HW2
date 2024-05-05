#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "You are using: " << argv[0] << " <name of the file>\n";
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error while opening the file " << filename << "\n";
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    string line;

    while (getline(file, line)) {
        lines++;
        characters += line.length();

        // Преброяване на думите
        size_t pos = 0;
        bool in_word = false;
        while (pos < line.length()) {
            if (isspace(line[pos])) {
                in_word = false;
            } else if (!in_word) {
                in_word = true;
                words++;
            }
            pos++;
        }
    }

    cout << "Count of the lines: " << lines << "\n";
    cout << "Count of the words: " << words << "\n";
    cout << "Count of the symbols: " << characters << "\n";

    file.close();
    return 0;
}
