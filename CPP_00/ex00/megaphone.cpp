#include <cstring>
#include <iostream>

void yell(const std::string& input) {
    for (int i = 0; input[i]; i++)
        std::cout << static_cast<char>(std::toupper(input[i]));
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    for (int i = 1; i < argc; i++)
        yell(argv[i]);
    std::cout << std::endl;
    return 0;
}
