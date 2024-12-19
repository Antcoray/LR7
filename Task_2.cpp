#include <cmath>
#include <iostream>
#include <string>

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
  } while (incorrectInput);
  return x;
}

void intro() {
  std::cout << "Условие задания: Найдите сумму двоичных чисел, заданных в "
               "естественной форме. Сложение выполните в обратном коде. Ответ "
               "выразите в естественной форме. \n ";
}

int CorrectInputNumber() {
  bool incorrect_input = false;
  bool error = false;
  double NumInput = 0.0;
  do {
    incorrect_input = false;
    std::string input = "";
    std::cin >> input;
    try {
      NumInput = stod(input);
    } catch (std::invalid_argument) {
      std::cout << "Некорректный ввод\n";
      incorrect_input = true;
      error = true;
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод\n";
      incorrect_input = true;
      error = true;
    }
    if (NumInput != static_cast<int>(NumInput) && !error) {
      incorrect_input = true;
      std::cout << "Некорректный ввод\n";
    }
  } while (incorrect_input);
  return static_cast<int>(NumInput);
}

std::string NormalToBinary(double NormalNum) {
  if (NormalNum == 0) {
    return "00000000000000000000000000000000";
  }
  std::string IntegerPartStr = "";
  std::string BinaryNum = "";
  std::string sign = NormalNum < 0 ? "1" : "0";

  int IntegerPart = abs(NormalNum);
  IntegerPartStr = std::to_string(static_cast<int>(IntegerPart));

  int TempInt = IntegerPart;
  std::string RemaindersInt = "";

  while (TempInt != 0) {
    int Remainder = TempInt % 2;
    TempInt /= 2;
    RemaindersInt.insert(0, std::to_string(Remainder));
  }

  RemaindersInt.insert(0, 31 - RemaindersInt.length(), '0');

  BinaryNum = sign + RemaindersInt;

  return BinaryNum;
}

std::string NormalToBinaryReverse(double NormalNum) {
  if (NormalNum == 0) {
    return "00000000000000000000000000000000";
  }
  std::string IntegerPartStr = "";
  std::string BinaryNum = "";
  std::string sign = NormalNum < 0 ? "1" : "0";

  int IntegerPart = abs(NormalNum);
  IntegerPartStr = std::to_string(static_cast<int>(IntegerPart));

  int TempInt = IntegerPart;
  std::string RemaindersInt = "";

  while (TempInt != 0) {
    int Remainder = TempInt % 2;
    TempInt /= 2;
    RemaindersInt.insert(0, std::to_string(Remainder));
  }

  RemaindersInt.insert(0, 31 - RemaindersInt.length(), '0');

  if (sign == "0") {
    BinaryNum = sign + RemaindersInt;
  } else {
    for (char& c : RemaindersInt) {
      if (c == '0') {
        c = '1';
      } else {
        c = '0';
      }
    }
    BinaryNum = sign + RemaindersInt;
  }
  return BinaryNum;
}

std::string sum(std::string left, std::string right) {
  std::string sum(32, '0');
  int NumberOfSymbols = 32;
  std::string temp = "0";
  for (int i = 0; i < 32; ++i) {
    //
    char li = left[31];
    char ri = right[31];

    // 0 0 0
    if (left[31 - i] == '0' && right[31 - i] == '0' && temp == "0") {
      sum[31 - i] = '0';
      temp = "0";
      continue;
    }
    // 1 0 0
    if (left[31 - i] == '1' && right[31 - i] == '0' && temp == "0") {
      sum[31 - i] = '1';
      temp = "0";
      continue;
    }
    // 0 1 0
    if (left[31 - i] == '0' && right[31 - i] == '1' && temp == "0") {
      sum[31 - i] = '1';
      temp = "0";
      continue;
    }
    // 1 1 0
    if (left[31 - i] == '1' && right[31 - i] == '1' && temp == "0") {
      sum[31 - i] = '0';
      temp = "1";
      continue;
    }
    // 0 0 1
    if (left[31 - i] == '0' && right[31 - i] == '0' && temp == "1") {
      sum[31 - i] = '1';
      temp = "0";
      continue;
    }
    // 1 0 1
    if (left[31 - i] == '1' && right[31 - i] == '0' && temp == "1") {
      sum[31 - i] = '0';
      temp = "1";
      continue;
    }
    // 0 1 1
    if (left[31 - i] == '0' && right[31 - i] == '1' && temp == "1") {
      sum[31 - i] = '0';
      temp = "1";
      continue;
    }
    // 1 1 1
    if (left[31 - i] == '1' && right[31 - i] == '1' && temp == "1") {
      sum[31 - i] = '1';
      temp = "1";
      continue;
    }
  }

  return sum;
}

int main() {
  intro();
  while (true) {
    std::cout << "Введите первое число:\n";

    int NormalNumLeft = CorrectInputNumber();
    std::string BinaryNumLeft = NormalToBinary(NormalNumLeft);

    std::cout << "Первое число в прямом коде: " << BinaryNumLeft << '\n';

    std::cout << "Введите второе число\n";

    int NormalNumRight = CorrectInputNumber();
    std::string BinaryNumRight = NormalToBinaryReverse(NormalNumRight);

    std::cout << "Второе число в обратном коде: " << BinaryNumRight << '\n';

    std::cout << "Сумма в прямом коде: " << sum(BinaryNumLeft, BinaryNumRight)
              << '\n';

    std::cout << "продолжить выполнение задания 2?\n";
    int a = correctInputk();
    if (a == 0) {
      break;
    }
  }
  return 0;
}