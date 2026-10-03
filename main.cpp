#include <iostream>

#include "src/calculator.hpp"

using namespace std;

int main() {
  // Prints out the number 7
  std::cout << evaluate("2 + 5") << endl;
 
  // Prints out the number 33
  std::cout << evaluate("3 + 6 * 5") << endl;
 
  // Prints out the number 20
  std::cout << evaluate("4 * (2 + 3)") << endl;
 
  // Prints out the number 2
  std::cout << evaluate("(7 + 9) / 8") << endl;

  // Prints out the number 8.125
  std::cout << evaluate("8 / 4 * 2") << endl;
}
