#include <iostream>

void intro() {
  std::cout << "Краткое условие задания: проверить делимость числа на число не "
               "используя операции умножения, деления, вычитания\n";
}

int correctInputk() {
  std::cout << "[1 - да / 0 - нет]";
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
    if (x != 1 && x != 0) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);//O(n)
  return x;
}

bool isDivisible(int number, int prime) {
  int q = 0;
  int r = 0;

  for (int bit = 31; bit >= 0; --bit) {
    // сдвиг остатка влево и добавление текущего бита
    r = (r << 1) | ((number >> bit) & 1);
    if (r >= prime) {
      r -= prime;
      q = (q << 1) | 1;
    } else {
      q = (q << 1);
    }
  }
  return r == 0;
}

bool* checkDivisibility(int* numbers, int numbersCount, int* p, int pCount) {
  bool* results = new bool[numbersCount * pCount];

  int idx = 0;
  for (int i = 0; i < numbersCount; ++i) {//O(n^2)
    for (int j = 0; j < pCount; ++j) {
      results[idx++] = isDivisible(numbers[i], p[j]);
    }
  }

  return results;
}

void outputResult(int* numbers, int numbersCount, int* p, int pCount,
                  bool* results) {
  int k = 0;
  for (int i = 0; i < numbersCount; ++i) {//O(n^2)
    for (int j = 0; j < pCount; ++j) {
      std::cout << "Число " << numbers[i]
                << (results[k++] ? " делится " : " не делится ") << "на "
                << p[j] << ".\n";
    }
  }
}

int main() {
  intro();
  while (true) {//O(n)
    int p[] = {7, 79, 107};
    int pCount = sizeof(p) / sizeof(p[0]);

    int count;
    std::cout << "Введите количество чисел для проверки: ";
    std::cin >> count;

    int* numbers = new int[count];

    std::cout << "Введите числа:\n";
    for (int i = 0; i < count; ++i) {
      std::cin >> numbers[i];
    }

    bool* results = checkDivisibility(numbers, count, p, pCount);

    outputResult(numbers, count, p, pCount, results);

    delete[] numbers;
    delete[] results;
    std::cout << "Продолжить выполнение задания 4?\n";
    int d = correctInputk();
    if (d == 0) {
      break;
    }
  }
  return 0;
}
