#include <iostream>
#include <fstream>

int handle_arguments(int argc, char* argv[]);
std::ofstream prepare_file();
void add_condition(std::ofstream& file, int number, bool odd);
void close_file(std::ofstream& file);

int main(int argc, char* argv[]) {

    const int goal_number = handle_arguments(argc, argv);

    std::ofstream file = prepare_file();

    bool odd = true;
    for (int i = 1; i < goal_number + 10; i++) {
        add_condition(file, i, odd);
        odd = !odd;
    }

    close_file(file);
    std::system("g++ Cursed.cpp -o out");
    std::string test = std::to_string(goal_number);
    std::string temp = ".\\out " + std::to_string(goal_number);
    std::system(temp.c_str());

}

int handle_arguments(int argc, char* argv[]) {
    if ( std::stoi(argv[1]) < 0 ) throw "invalid argument";
    return std::stoi(argv[1]);
}

std::ofstream prepare_file() {
    std::ofstream file = std::ofstream("Cursed.cpp");
    file << "#include <iostream>\n";
    file << "int main(int argc, char* argv[]) {\n";
    file << "\tint number = std::stoi(argv[1]);\n";
    file << "\tif(number == 0) std::cout << \"number 0 is zero :)\";\n";
    file << "\telse ";
    return file;
}

void add_condition(std::ofstream& file, int number, bool odd) {
    file << "if ( number == " << number << ") std::cout << \"number " << number << " is ";
    odd ? file << "odd" : file << "even";
    file << "\";\n";
    file << "\telse ";
}

void close_file(std::ofstream& file) {
    file << "\tstd::cout << \"Number out of scope :(\"\n;";
    file << "}\n";
    file.close();
}