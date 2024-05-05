#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void tail(const string& filename, int numLines) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening the file: " << filename << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
        if (lines.size() > numLines) {
            lines.erase(lines.begin());
        }
    }

    for (const string& l : lines) {
        cout << l << endl;
    }

    file.close();
}

int main() {
    string filename = "myfile.txt";
    int numLines = 1;

    tail(filename, numLines);

    return 0;
}
