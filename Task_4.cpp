#include <iostream>

bool isDivisible(int number, int prime) {
  int quotient = 0;
  int remainder = 0;

  for (int bit = 31; bit >= 0; --bit) {
    remainder = (remainder << 1) | ((number >> bit) & 1);
    if (remainder >= prime) {
      remainder -= prime;
      quotient = (quotient << 1) | 1;
    } else {
      quotient = (quotient << 1);
    }
  }
  return remainder == 0;
}

bool* checkDivisibility(int* numbers, int numbersCount, int* primes,
                        int primesCount) {
  bool* results = new bool[numbersCount * primesCount];

  int idx = 0;
  for (int i = 0; i < numbersCount; ++i) {
    for (int j = 0; j < primesCount; ++j) {
      results[idx++] = isDivisible(numbers[i], primes[j]);
    }
  }

  return results;
}

void printResults(int* numbers, int numbersCount, int* primes, int primesCount,
                  bool* results) {
  int idx = 0;
  for (int i = 0; i < numbersCount; ++i) {
    for (int j = 0; j < primesCount; ++j) {
      std::cout << "Число " << numbers[i]
                << (results[idx++] ? " делится " : " не делится ") << "на "
                << primes[j] << ".\n";
    }
  }
}

int main() {
  int* numbers;
  int primes[] = {7, 79, 107};
  int primesCount = sizeof(primes) / sizeof(primes[0]);

  int count;
  std::cout << "Введите количество чисел для проверки: ";
  std::cin >> count;

  numbers = new int[count];

  std::cout << "Введите числа:\n";
  for (int i = 0; i < count; ++i) {
    std::cin >> numbers[i];
  }

  bool* results = checkDivisibility(numbers, count, primes, primesCount);

  printResults(numbers, count, primes, primesCount, results);

  delete[] numbers;
  delete[] results;

  return 0;
}
