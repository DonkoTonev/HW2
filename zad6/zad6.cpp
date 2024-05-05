#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename << "\n";
        return 1;
    }

    int lines = 0, words = 0, characters = 0;
    string line;

    while (getline(file, line)) {
        lines++;
        characters += line.length();

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

    if (!line.empty()) {
        lines++;
    }

    cout << "Number of lines: " << lines << "\n";
    cout << "Number of words: " << words << "\n";
    cout << "Number of characters: " << characters << "\n";

    file.close();
    return 0;
}
