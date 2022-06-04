#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>


int main() {
    std::fstream file;
    std::string line;
    std::string number;
    unsigned int answer = UINT64_MAX;

    file.open("INPUT.txt", std::fstream::in);

    getline(file, number);

    std::vector<std::vector<int>> vector(std::stoi(number));

    for (int i = 0; i < vector.size(); ++i) {
        getline(file, line);
        std::stringstream streamLine(line);

        while ( getline(streamLine, number, ' ') ) {
            vector[i].push_back(std::stoi(number));
        }
    }

    for (int i = 0; i < vector.size(); ++i) {
        for (int j = 0; j < vector.size(); ++j) {
            if (i == j) {
                continue;
            }

            for (int k = 0; k < vector.size(); ++k) {
                if (k == i || k == j) {
                    continue;
                }

                int sum = vector[i][j] + vector[j][k] + vector[i][k];
                if (sum < answer) {
                    answer = sum;
                }
            }

        }
    }

    std::fstream out;
    out.open("OUTPUT.txt", std::fstream::out);
    out << answer;

    return 0;
}
