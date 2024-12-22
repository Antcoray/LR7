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
  } while (incorrectInput); //O(n)
  return x;
}

void intro() {
  std::cout << "Условие задания: перевести числа из естественной формы в "
               "обратный код \n";
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
  } while (incorrect_input);//O(n)
  return static_cast<int>(NumInput);
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

  while (TempInt != 0) { //O(n)
    int Remainder = TempInt % 2;
    TempInt /= 2;
    RemaindersInt.insert(0, std::to_string(Remainder));
  }

  RemaindersInt.insert(0, 31 - RemaindersInt.length(), '0'); //O(n)

  if (sign == "0") {
    BinaryNum = sign + RemaindersInt;
  } else {
    for (char& c : RemaindersInt) {//O(n)
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

int main() {
  intro();
  while (true) {//O(n)
    std::cout
        << "Введите число в естественной форме для перевода в обратный код\n";
    int NormalNum = CorrectInputNumber();
    std::string BinaryNum = NormalToBinaryReverse(NormalNum);

    std::cout << "Обратный код числа: " << BinaryNum << '\n';
    std::cout << "продолжить выполнение задания 1?\n";
    int a = correctInputk();
    if (a == 0) {
      break;
    }
  }
  return 0;
}
