#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

double CorrectInputNumber() {
  bool incorrect_input = false;
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
    } catch (std::out_of_range) {
      std::cout << "Некорректный ввод\n";
      incorrect_input = true;
    }
  } while (incorrect_input);
  return NumInput;
}

std::string NormalToBinary(double NormalNum) {
  std::string IntegerPartStr = "";
  std::string FractionalPartStr = "";
  std::string BinaryNum = "";
  std::string sign = NormalNum < 0 ? "1" : "0";
  // разделяем исходное число на целую и дробную часть
  double IntegerPart = 0;
  double FractionalPart = 0;

  FractionalPart = modf(NormalNum, &IntegerPart);
  int IntegerPartAsInt = static_cast<int>(IntegerPart);
  IntegerPartStr = std::to_string(static_cast<int>(IntegerPart));
  // переводим в двоичную систему счисления целую часть
  int TempInt = IntegerPartAsInt;
  std::string RemaindersInt = "";
  while (TempInt != 0) {
    int Remainder = TempInt % 2;
    TempInt /= 2;
    RemaindersInt.insert(0, std::to_string(Remainder));
  }
  // переводим в двоичную систему счисления дробную часть
  double TempFrac = FractionalPart;
  std::string RemaindersFrac = "";
  int i = 0;
  while (TempFrac != 0 && i < 12) {
    TempFrac *= 2;
    int Remainder = static_cast<int>(TempFrac);
    TempFrac = TempFrac - Remainder;
    RemaindersFrac.append(std::to_string(Remainder));
    ++i;
  }
  return RemaindersFrac;
}

int main() {
  double NormalNum = CorrectInputNumber();
  std::string BinaryNum = NormalToBinary(NormalNum);
  std::cout << BinaryNum;
  return 0;
}
