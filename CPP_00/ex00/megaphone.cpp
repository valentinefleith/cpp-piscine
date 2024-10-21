#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
  }
  for (int i = 1; i < argc; i++) {
    int len = std::strlen(argv[i]);
    for (int j = 0; j < len; j++) {
      std::cout << (char)std::toupper(argv[i][j]);
    }
  }
  std::cout << std::endl;
  return 0;
}
