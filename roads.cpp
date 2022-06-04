#include <fstream>
#include <string>


int main() {
    std::fstream file;
    std::string line;
    int answer = 0;

    file.open("INPUT.txt", std::fstream::in);
    
    getline(file, line);

    while( !file.eof() ) {
        getline(file, line);

	for (auto&& item : line) {
	    if (item == '1') ++answer;
	} 
    }

    std::fstream out;
    out.open("OUTPUT.txt", std::fstream::out);
    out << answer / 2;

    return 0;
}
