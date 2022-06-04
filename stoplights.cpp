#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>


int main() {
    std::fstream file;
    std::string line;
    std::string number;

    file.open("INPUT.txt", std::fstream::in);

    getline(file, line);

    for (auto&& item : line) {
        if (item >= '0' && item <= '9') {
            number += item;
        }
        else {
            break;
        }
    }

    std::vector<int> answer(std::stoi(number), 0);

    while ( !file.eof() ) {
        getline(file, line);
        std::stringstream streamLine(line);

        if (line == "") {
            break;
        }

        getline(streamLine, number, ' ');
        answer[std::stoi(number) - 1] += 1;

        getline(streamLine, number, ' ');
        answer[std::stoi(number) - 1] += 1;
    }


    std::fstream out;
    out.open("OUTPUT.txt", std::fstream::out);

    for (auto&& item : answer) {
        out << item << ' ';
    }

    return 0;
}
