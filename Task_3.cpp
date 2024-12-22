#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

std::string Sum(const std::string& num1, const std::string& num2, int base);

void intro() {
  std::cout
      << "Краткое условие задания: разработать функции для выполнения \n"
         "операции сложения и функции для выполнения операции вычитания \n"
         "в произвольной системе счисления\n";
}

int charToValue(char c) {
  int result = 0;
  if ('0' <= c && c <= '9') {
    result = c - '0';
  }
  // a=10, b=11 ... z=35
  if ('a' <= c && c <= 'z') {
    result = c - 'a' + 10;
  }
  // A=10, B=11 ... Z=35
  if ('A' <= c && c <= 'Z') {
    result = c - 'A' + 10;
  }
  return result;
}

char valueToChar(int value) {
  char result = ' ';
  if (0 <= value && value <= 9) {
    result = '0' + value;
  }
  if (10 <= value && value <= 35) {
    result = 'A' + (value - 10);
  }
  return result;
}

std::string difference(const std::string& num1, const std::string& num2,
                       int base) {
  bool isNegative1 = num1[0] == '-';
  bool isNegative2 = num2[0] == '-';
  std::string n1 = isNegative1 ? num1.substr(1) : num1;
  std::string n2 = isNegative2 ? num2.substr(1) : num2;
  if (isNegative1 && isNegative2) {
    if (n1.size() < n2.size() || n1.size() == n2.size() && n1 < n2) {
      return difference(n2, n1, base);
    }
    if (n1.size() > n2.size() || n1.size() == n2.size() && n1 > n2) {
      return "-" + difference(n1, n2, base);
    }
  }
  if (isNegative1 != isNegative2) {
    if (isNegative1) {
      return "-" + Sum(n1, n2, base);
    }
    if (isNegative2) {
      return Sum(n1, n2, base);
    }
  }
  if (!isNegative1 && !isNegative2) {
    if (n1.size() < n2.size() || n1.size() == n2.size() && n1 < n2) {
      return "-" + difference(n2, n1, base);
    }
  }
  std::string result;
  int temp = 0;
  int i = n1.size() - 1;
  int j = n2.size() - 1;


  while (i >= 0 || j >= 0 || temp > 0) {// O(n) n=max(num1,num2)
    int digit_1 = 0;
    int digit_2 = 0;
    if (i >= 0) {
      digit_1 = charToValue(n1[i]);
      --i;
    } else {
      digit_1 = 0;
    }
    if (j >= 0) {
      digit_2 = charToValue(n2[j]);
      --j;
    } else {
      digit_2 = 0;
    }

    int diff = digit_1 - digit_2 - temp;
    if (diff < 0) {
      diff += base;
      temp = 1;
    } else {
      temp = 0;
    }
    result.push_back(valueToChar(diff));
  }

  while (result.size() > 1 && result.back() == '0') {//O(n)
    result.pop_back();
  }

  std::reverse(result.begin(), result.end());
  return result;
}

std::string Sum(const std::string& num1, const std::string& num2, int base) {
  bool isNegative1 = num1[0] == '-';
  bool isNegative2 = num2[0] == '-';
  std::string n1 = isNegative1 ? num1.substr(1) : num1;
  std::string n2 = isNegative2 ? num2.substr(1) : num2;

  std::string result;
  int temp = 0;
  int i = n1.size() - 1;
  int j = n2.size() - 1;

  while (i >= 0 || j >= 0 || temp > 0) {// O(n) n=max(num1,num2)
    int digit_1 = 0;
    int digit_2 = 0;
    if (i >= 0) {
      digit_1 = charToValue(n1[i]);
      --i;
    } else {
      digit_1 = 0;
    }
    if (j >= 0) {
      digit_2 = charToValue(n2[j]);
      --j;
    } else {
      digit_2 = 0;
    }

    int sum = digit_1 + digit_2 + temp;
    temp = sum / base;
    result.push_back(valueToChar(sum % base));
  }

  std::reverse(result.begin(), result.end());

  if (isNegative1 && isNegative2) {
    return "-" + result;

  } else if (isNegative1 != isNegative2) {
    std::string diff;

    if (isNegative1) {
      diff = difference(n2, n1, base);
      return diff;
    } else {
      diff = difference(n1, n2, base);
      return diff;
    }
  }

  return result;
}

bool checkForEquality(std::string str, int base) {
  const char PossibleValues[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                                   '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                   'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                   'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  if (str[0] == '-') {
    str = str.substr(1);
  }

  for (char c : str) {//O(n^2)
    c = std::tolower(c);

    bool valid = false;

    for (int i = 0; i < base; ++i) {
      if (c == PossibleValues[i]) {
        valid = true;
        break;
      }
    }

    if (!valid) {
      return false;
    }
  }

  return true;
}

std::string correctInputk(int base) {
  std::string x = "";
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
    if (!checkForEquality(x, base)) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);//O(n)
  return x;
}

int correctInputBase() {
  std::cout << "Введите основание системы счисления [от 2 до 36]: ";
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
    if (!(x >= 2 && x <= 36) && incorrectInput == false) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);//O(n)
  return x;
}

int correctInputd() {
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
    if (x != 1 && x != 0 && incorrectInput == false) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);//O(n)
  return x;
}

std::string correctInputOperator() {
  std::cout << "Введите операцию (+ или -): ";
  std::string x = "";
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
    if (x != "+" && x != "-" && incorrectInput == false) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);//O(n)
  return x;
}

int main() {
  intro();
  while (true) {//O(n)
    int base;
    std::string num1 = "", num2 = "", Operator = "";

    base = correctInputBase();

    std::cout << "Введите первое число: ";

    num1 = correctInputk(base);

    std::cout << "Введите второе число: ";

    num2 = correctInputk(base);

    Operator = correctInputOperator();

    if (Operator == "+") {
      std::cout << "Результат: " << Sum(num1, num2, base) << "\n";
    } else if (Operator == "-") {
      std::cout << "Результат: " << difference(num1, num2, base) << "\n";
    }
    std::cout << "продолжить выполнение задания 2?\n";
    int a = correctInputd();
    if (a == 0) {
      break;
    }
  }
  return 0;
}