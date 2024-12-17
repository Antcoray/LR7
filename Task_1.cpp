#include <cmath>
#include <iostream>
#include <string>

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

  if (sign == "0") {
    BinaryNum = RemaindersInt;
  } else {
    for (char& c : RemaindersInt) {
      if (c == '0') {
        c = '1';
      } else {
        c = '0';
      }
    }
    BinaryNum = RemaindersInt;
  }
  return BinaryNum;
}

int main() {
  int NormalNum = CorrectInputNumber();
  std::string BinaryNum = NormalToBinary(NormalNum);
  std::cout << BinaryNum;
  return 0;
}
