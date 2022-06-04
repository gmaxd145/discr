#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>


int main() {
    std::fstream file;
    std::string line;
    std::string number;
    int answer = 0;

    file.open("INPUT.txt", std::fstream::in);

    getline(file, number);

    std::vector<std::vector<int>> vector(std::stoi(number));
    std::vector<int> color;

    for (int i = 0; i < vector.size(); ++i) {
        getline(file, line);
        std::stringstream streamLine(line);

        while ( getline(streamLine, number, ' ') ) {
            vector[i].push_back(std::stoi(number));
        }
    }

    getline(file, line);

    getline(file, line);
    std::stringstream streamLine(line);

    while ( getline(streamLine, number, ' ') ) {
        color.push_back(std::stoi(number));
    }

    for (int i = 0; i < vector.size(); ++i) {
        for (int j = 0; j < vector.size(); ++j) {
            if (vector[i][j] == 1) {
                if (color[i] != color[j]) {
                    ++answer;
                }
            }
        }
    }

    std::fstream out;
    out.open("OUTPUT.txt", std::fstream::out);
    out << answer / 2;

    return 0;
}
