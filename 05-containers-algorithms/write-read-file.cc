#include <fstream>
#include <iostream>
#include <cstdio>


void error(std::string msg, int exit_code=1) {
    std::cerr << msg << "\n";
    exit(exit_code);
}


void write_to_file(std::string filename) {
    std::ofstream ofs(filename);
    if (!ofs) {
        error("Couldn't open " + filename + " for writing");
    }

    for (auto i = 0; i < 500; ++i) {
        ofs << i << "\n";
    }
}


void read_from_file(std::string filename) {
    // Reading in from file
    std::string tmp;
    std::ifstream ifs(filename);
    if (!ifs) {
        error("Couldn't open " + filename + " for reading");
    }

    int i = 0;
    std::cout << "Printing every tenth line:\n";
    while (!(ifs >> tmp).eof()) {
        if (i % 10 == 0) {
            std::cout << "read back: " << tmp << "\n";
        }
        ++i;
    }
}


int main() {
    std::string filename = "many-numbers";

    write_to_file(filename);

    read_from_file(filename);

    std::remove(filename.c_str());
}
