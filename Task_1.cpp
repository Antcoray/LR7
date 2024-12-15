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
  std::string IntegerPart = "";
  std::string FractionalPart = "";
  std::string NormalNumStr = std::to_string(NormalNum);
  std::string BinaryNum = "";
  std::string sign = NormalNum < 0 ? "1" : "0";
  int DotIndex = NormalNumStr.find(".");
  IntegerPart = IntegerPart.insert(0, NormalNumStr, 0, DotIndex);
  FractionalPart = NormalNumStr.substr(DotIndex + 1);
  return FractionalPart;
}

int main() {
  double NormalNum = CorrectInputNumber();
  std::string BinaryNum = NormalToBinary(NormalNum);
  std::cout << BinaryNum;
  return 0;
}