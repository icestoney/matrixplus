#include "s21_tests.h"

#include <iostream>

void printHead();

int main(int argc, char **argv) {
  printHead();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void printHead() {
  std::cout << "\033[34m*******************************************************"
               "*****************\n\033[39m";
  std::cout << "\033[34m***\033[39m         Тесты s21_matrix_oop.a        "
               "\033[34m***\033[39m        \033[32mshericen\033[39m        "
               "\033[34m***\033[39m\n";
  std::cout << "\033[34m*******************************************************"
               "*****************\n\n\033[39m";
}