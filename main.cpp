#include <iostream>

#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"
#include "Task_5.h"

void intro6() {
  std::string info = R"(
    ___________________________________________
    | Лабораторная работа 7                   |
    |-----------------------------------------|
    |Выполнил студент группы 453501           |
    |Колесников Антон Сергеевич               |
    |Вариант 12                               |
    |_________________________________________|
    
    )";

  std::cout << info << "\n";
}

int correctInputk6() {
  std::cout << "Введите номер задния[1/2/3/4/5] или 0 чтобы выйти\n";
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (!(x >= 0 && x <= 5)) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);  // O(n)
  return x;
}

int main() {
  while (true) {
    intro6();
    int k = correctInputk6();
    if (k == 0) {
      break;
    }
    if (k == 1) {
      Task_1_main();
    }
    if (k == 2) {
      Task_2_main();
    }
    if (k == 3) {
      Task_3_main();
    }
    if (k == 4) {
      Task_4_main();
    }
    if (k == 5) {
      Task_5_main();
    }
  }
  return 0;
}
