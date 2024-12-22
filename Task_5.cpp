#include <algorithm>
#include <iostream>
#include <string>

const bool combinations30Day1[31][5] = {
    // 0
    {false, false, false, false, false},
    // 1
    {true, false, false, false, false},
    // 2
    {false, true, false, false, false},
    // 3
    {false, false, true, false, false},
    // 4
    {false, false, false, true, false},
    // 5
    {false, false, false, false, true},
    // 6
    {true, true, false, false, false},
    // 7
    {true, false, true, false, false},
    // 8
    {true, false, false, true, false},
    // 9
    {true, false, false, false, true},
    // 10
    {false, true, true, false, false},
    // 11
    {false, true, false, true, false},
    // 12
    {false, true, false, false, true},
    // 13
    {false, false, true, true, false},
    // 14
    {false, false, true, false, true},
    // 15
    {false, false, false, true, true},
    // 16
    {true, true, true, false, false},
    // 17
    {true, true, false, true, false},
    // 18
    {true, true, false, false, true},
    // 19
    {true, false, true, true, false},
    // 20
    {true, false, true, false, true},
    // 21
    {true, false, false, true, true},
    // 22
    {false, true, true, true, false},
    // 23
    {false, true, true, false, true},
    // 24
    {false, true, false, true, true},
    // 25
    {false, false, true, true, true},
    // 26
    {true, true, true, true, false},
    // 27
    {true, true, true, false, true},
    // 28
    {true, true, false, true, true},
    // 29
    {true, false, true, true, true},
    // 30
    {false, true, true, true, true}};

const bool combinations16[16][4] = {
    // 1
    {false, false, false, false},
    // 2
    {true, false, false, false},
    // 3
    {false, true, false, false},
    // 4
    {true, true, false, false},
    // 5
    {false, false, true, false},
    // 6
    {true, false, true, false},
    // 7
    {false, true, true, false},
    // 8
    {true, true, true, false},
    // 9
    {false, false, false, true},
    // 10
    {true, false, false, true},
    // 11
    {false, true, false, true},
    // 12
    {true, true, false, true},
    // 13
    {false, false, true, true},
    // 14
    {true, false, true, true},
    // 15
    {false, true, true, true},
    // 16
    {true, true, true, true}};

const bool combinations8[8][3] = {
    // 1
    {false, false, false},
    // 2
    {true, false, false},
    // 3
    {false, true, false},
    // 4
    {true, true, false},
    // 5
    {false, false, true},
    // 6
    {true, false, true},
    // 7
    {false, true, true},
    // 8
    {true, true, true}};

const bool combinations4[4][2] = {
    // 1
    {false, false},
    // 2
    {true, false},
    // 3
    {false, true},
    // 4
    {true, true}};

const bool combinations2[2][1] = {
    // 1
    {false},
    // 2
    {true}};

const bool combinations30Day2[30][5] = {
    // 1
    {false, false, false, false, false},
    // 2
    {true, false, false, false, false},
    {false, true, false, false, false},
    {true, true, false, false, false},
    {false, false, true, false, false},
    {true, false, true, false, false},
    {false, true, true, false, false},
    {true, true, true, false, false},
    {false, false, false, true, false},
    {true, false, false, true, false},
    {false, true, false, true, false},
    {true, true, false, true, false},
    {false, false, true, true, false},
    {true, false, true, true, false},
    //
    {false, true, true, true, false},
    {true, true, true, true, false},
    {false, false, false, false, true},
    {true, false, false, false, true},
    {false, true, false, false, true},
    {true, true, false, false, true},
    {false, false, true, false, true},
    {true, false, true, false, true},
    {false, true, true, false, true},
    {true, true, true, false, true},
    {false, false, false, true, true},
    {true, false, false, true, true},
    {false, true, false, true, true},
    {true, true, false, true, true},
    {false, false, true, true, true},
    {true, false, true, true, true}};

int correctInputD() {
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

void CONTINUE() {
  std::cout << "Введите любой символ чтобы продолжить...";
  std::string a;
  std::cin >> a;
}

void intro() {
  std::string barrels = R"(
   _______        _______               _______
  /       \      /       \             /       \
 |         |    |         |           |         |
|     1     |  |     2     |         |    240    |
 |         |    |         |           |         |
  \_______/      \_______/   .  .  .   \_______/
)";

  std::cout
      << " \n\033[34mВЫ\033[0m - \033[31mПользователь\033[0m, и ваша задача "
         "ОТРАВИТЬ одну из "
         "240 бочек "
         "для праздника Патриция. Загадайте номер отравленной бочки \n \n" +
             barrels
      << "\n\n";

  CONTINUE();
}

void Day0() {
  std::cout << "\033[2J\033[2H";
  std::cout << "\033[1;31mВАС ПОЙМАЛИ И ОТПРАВИЛИ В АД! Вы будете проверять "
               "консольный ввод до конца своих дней!\n\n\033[0mДалее "
               "\033[34mВЫ\033[0m будете "
               "отыгрывать роль \033[1;32mдруг Патриция\033[0m, которому надо "
               "найти бочку, отравленную "
               "\033[31mПользователем\033[0m\n\n";
  CONTINUE();
}

void Day1intro() {
  std::string art = R"(
       _,.
    ,` -.)
   ( _/-\\-._
  /,|`--._,-^|            ,
  \_| |`-._/||          ,'|
    |  `-, / |         /  /
    |     || |        /  /
     `r-._||/   __   /  /                       И у вас есть 5 рабов... 
 __,-<_     )`-/  `./  /
'  \   `---'   \   /  /                                   :(     D:   :(    :(    :(
    |           |./  /                                    /|\   /|\   /|\   /|\   /|\
    /           //  /                                      /\    /\    /\    /\    /\
\_/' \         |/  /
 |    |   _,^-'/  /                             И 2 дня до праздника Патриция
 |    , ``  (\/  /_                               
  \,.->._    \X-=/^
  (  /   `-._//^`
   `Y-.____(__}
    |     {__)
          ())";
  std::cout << "\033[2J\033[2H";
  std::cout << "\n\033[1;34mВЫ\033[0m - \033[1;32mдруг Патриция\033[0m\n"
            << art << "\n\n";
  std::cout
      << "У вас есть план как найти нужную бочку: Нужно поделить 240 бочек на "
         "210 бочек, которые будут проверяться в 1 день и 30, которые будут "
         "проверяться во второй. Первые 80 бочек будут проверяться отрядами из "
         "1 человека на 16 бочек. Следующие 80 бочек будут проверяться "
         "отрядами по 2 человека на 8 бочек. Затем 40 бочек по 3 раба на 4 "
         "бочки. Оставшиеся 10 бочек будут проверяться по 4 раба на 2 бочки. "
         "Поделив рабов на 30 уникальных отрядов, мы сможем достаточно сузить "
         "круг возможных бочек с отравой, чтобы на 2 день точно определить "
         "нужную бочку \n\n";
  CONTINUE();
}

std::string DecideWhichSlaveForTableDay1(int i) {
  std::string listOfSlaves = "00000";
  for (int j = 1; j < 6; ++j) {
    if (combinations30Day1[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

std::string BarrelsInTable(int i) {
  std::string barrels = "";
  if (i == 1) {
    barrels = "1 - 16";
  }
  if (i == 2) {
    barrels = "17 - 32";
  }
  if (i == 3) {
    barrels = "33 - 48";
  }
  if (i == 4) {
    barrels = "49 - 64";
  }
  if (i == 5) {
    barrels = "65 - 80";
  }
  if (i == 6) {
    barrels = "81 - 88";
  }
  if (i == 7) {
    barrels = "89 - 96";
  }
  if (i == 8) {
    barrels = "97 - 104";
  }
  if (i == 9) {
    barrels = "105 - 112";
  }
  if (i == 10) {
    barrels = "113 - 120";
  }
  if (i == 11) {
    barrels = "121 - 128";
  }
  if (i == 12) {
    barrels = "129 - 136";
  }
  if (i == 13) {
    barrels = "137 - 144";
  }
  if (i == 14) {
    barrels = "145 - 152";
  }
  if (i == 15) {
    barrels = "153 - 160";
  }
  if (i == 16) {
    barrels = "161 - 164";
  }
  if (i == 17) {
    barrels = "165 - 168";
  }
  if (i == 18) {
    barrels = "169 - 172";
  }
  if (i == 19) {
    barrels = "173 - 176";
  }
  if (i == 20) {
    barrels = "177 - 180";
  }
  if (i == 21) {
    barrels = "181 - 184";
  }
  if (i == 22) {
    barrels = "185 - 188";
  }
  if (i == 23) {
    barrels = "189 - 192";
  }
  if (i == 24) {
    barrels = "193 - 196";
  }
  if (i == 25) {
    barrels = "197 - 200";
  }
  if (i == 26) {
    barrels = "201 - 202";
  }
  if (i == 27) {
    barrels = "203 - 204";
  }
  if (i == 28) {
    barrels = "205 - 206";
  }
  if (i == 29) {
    barrels = "207 - 208";
  }
  if (i == 30) {
    barrels = "209 - 210";
  }
  return barrels;
}

void PrintTableDay1() {
  std::cout << "\033[2J\033[2H";
  std::cout << "\033[1;31mНАСТУПИЛ ДЕНЬ 1!\n\n\033[0m";

  std::string startOfTable = R"(
_____________________________________________
| номер отряда | номера рабов | группы бочек|
|-------------------------------------------|)";
  std::cout << startOfTable << '\n';
  for (int i = 1; i < 31; ++i) {
    if (i < 10) {
      std::cout << "|       " << i << "      |"
                << DecideWhichSlaveForTableDay1(i) << "         |"
                << " " + BarrelsInTable(i) << "\n";
    }
    if (i >= 10) {
      std::cout << "|       " << i << "     |"
                << DecideWhichSlaveForTableDay1(i) << "         |"
                << " " + BarrelsInTable(i) << "\n";
    }
  }
  std::cout << "_____________________________________________\n\n";
}

int correctInputk() {
  std::cout << "Введите номер погибшего отряда (или 0 если все живы):";
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
    if (!(x >= 0 && x <= 30)) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

std::string DecideWhichSlaveForTable30Day2(int i) {
  std::string listOfSlaves = "00000";
  for (int j = 1; j < 6; ++j) {
    if (combinations30Day2[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

int findRightBarrelInput0(bool slave1, bool slave2, bool slave3, bool slave4,
                          bool slave5) {
  for (int i = 0; i < 31; ++i) {
    if (combinations30Day2[i][0] == slave1 &&
        combinations30Day2[i][1] == slave2 &&
        combinations30Day2[i][2] == slave3 &&
        combinations30Day2[i][3] == slave4 &&
        combinations30Day2[i][4] == slave5) {
      return 210 + i + 1;
    }
  }
  return -1;
}

int findRightBarrelInput1to5(bool slave1, bool slave2, bool slave3, bool slave4,
                             int num) {
  for (int i = 0; i < 16; ++i) {
    if (combinations16[i][0] == slave1 && combinations16[i][1] == slave2 &&
        combinations16[i][2] == slave3 && combinations16[i][3] == slave4) {
      return (num - 1) * 16 + i + 1;
    }
  }
  return -1;
}

int findRightBarrelInput6to15(bool slave1, bool slave2, bool slave3, int num) {
  for (int i = 0; i < 8; ++i) {
    if (combinations16[i][0] == slave1 && combinations16[i][1] == slave2 &&
        combinations16[i][2] == slave3) {
      return 80 + (num - 6) * 8 + i + 1;
    }
  }
  return -1;
}

int findRightBarrelInput16to25(bool slave1, bool slave2, int num) {
  for (int i = 0; i < 4; ++i) {
    if (combinations4[i][0] == slave1 && combinations4[i][1] == slave2) {
      return 160 + (num - 16) * 4 + i + 1;
    }
  }
  return -1;
}

int findRightBarrelInput26to30(bool slave1, int num) {
  for (int i = 0; i < 2; ++i) {
    if (combinations4[i][0] == slave1) {
      return 200 + (num - 26) * 2 + i + 1;
    }
  }
  return -1;
}

std::string DecideWhichSlaveForTable16Day2(int i) {
  std::string listOfSlaves = "0000";
  for (int j = 1; j < 5; ++j) {
    if (combinations16[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

std::string DecideWhichSlaveForTable8Day2(int i) {
  std::string listOfSlaves = "000";
  for (int j = 1; j < 4; ++j) {
    if (combinations8[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

std::string DecideWhichSlaveForTable4Day2(int i) {
  std::string listOfSlaves = "00";
  for (int j = 1; j < 3; ++j) {
    if (combinations8[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

std::string DecideWhichSlaveForTable2Day2(int i) {
  std::string listOfSlaves = "0";
  for (int j = 1; j < 2; ++j) {
    if (combinations8[i][j - 1]) {
      listOfSlaves[j - 1] = j + '0';
    } else {
      listOfSlaves[j - 1] = ' ';
    }
  }
  return listOfSlaves;
}

int Day2(int k) {
  std::string startOfTable = R"(
______________________________
| номера рабов | группы бочек|
|----------------------------|)";
  std::cout << "\033[2J\033[2H";
  std::cout << "\033[1;31mНАСТУПИЛ ДЕНЬ 2!\033[0m\n\n";
  // 30
  if (k == 0) {
    std::cout << startOfTable << '\n';
    for (int i = 1; i < 31; ++i) {
      if (i < 10) {
        std::cout << "|" << DecideWhichSlaveForTable30Day2(i - 1)
                  << "         |"
                  << " " << 210 + i << "\n";
      }
      if (i >= 10) {
        std::cout << "|" << DecideWhichSlaveForTable30Day2(i - 1)
                  << "         |"
                  << " " << 210 + i << "\n";
      }
    }
    std::cout << "------------------------------\n\n";

    std::cout << "Жив ли раб 1?";
    bool slave1 = !correctInputD();
    std::cout << "Жив ли раб 2?";
    bool slave2 = !correctInputD();
    std::cout << "Жив ли раб 3?";
    bool slave3 = !correctInputD();
    std::cout << "Жив ли раб 4?";
    bool slave4 = !correctInputD();
    std::cout << "Жив ли раб 5?";
    bool slave5 = !correctInputD();

    int result = findRightBarrelInput0(slave1, slave2, slave3, slave4, slave5);
    return result;
  } else if (k <= 5 && k >= 1) {
    std::cout << startOfTable << '\n';
    for (int i = 1; i < 17; ++i) {
      if (i < 10) {
        std::cout << "|" << DecideWhichSlaveForTable16Day2(i - 1)
                  << "         |"
                  << " " << (k - 1) * 16 + i << "\n";
      }
      if (i >= 10) {
        std::cout << "|" << DecideWhichSlaveForTable16Day2(i - 1)
                  << "         |"
                  << " " << (k - 1) * 16 + i << "\n";
      }
    }
    std::cout << "------------------------------\n\n";

    std::cout << "Жив ли раб 1?";
    bool slave1 = !correctInputD();
    std::cout << "Жив ли раб 2?";
    bool slave2 = !correctInputD();
    std::cout << "Жив ли раб 3?";
    bool slave3 = !correctInputD();
    std::cout << "Жив ли раб 4?";
    bool slave4 = !correctInputD();

    int result = findRightBarrelInput1to5(slave1, slave2, slave3, slave4, k);
    return result;
  } else if (k <= 15 && k >= 6) {
    std::cout << startOfTable << '\n';
    for (int i = 1; i < 9; ++i) {
      if (i < 10) {
        std::cout << "|" << DecideWhichSlaveForTable8Day2(i - 1) << "         |"
                  << " " << 80 + (k - 6) * 8 + i << "\n";
      }
      if (i >= 10) {
        std::cout << "|" << DecideWhichSlaveForTable8Day2(i - 1) << "         |"
                  << " " << 80 + (k - 6) * 8 + i << "\n";
      }
    }
    std::cout << "------------------------------\n\n";

    std::cout << "Жив ли раб 1?";
    bool slave1 = !correctInputD();
    std::cout << "Жив ли раб 2?";
    bool slave2 = !correctInputD();
    std::cout << "Жив ли раб 3?";
    bool slave3 = !correctInputD();

    int result = findRightBarrelInput6to15(slave1, slave2, slave3, k);
    return result;
  } else if (k <= 25 && k >= 16) {
    std::cout << startOfTable << '\n';
    for (int i = 1; i < 5; ++i) {
      if (i < 10) {
        std::cout << "|" << DecideWhichSlaveForTable4Day2(i - 1) << "         |"
                  << " " << 160 + (k - 16) * 4 + i << "\n";
      }
      if (i >= 10) {
        std::cout << "|" << DecideWhichSlaveForTable4Day2(i - 1) << "         |"
                  << " " << 160 + (k - 16) * 4 + i << "\n";
      }
    }
    std::cout << "------------------------------\n\n";

    std::cout << "Жив ли раб 1?";
    bool slave1 = !correctInputD();
    std::cout << "Жив ли раб 2?";
    bool slave2 = !correctInputD();

    int result = findRightBarrelInput16to25(slave1, slave2, k);
    return result;
  } else if (k <= 30 && k >= 26) {
    std::cout << startOfTable << '\n';
    for (int i = 1; i < 3; ++i) {
      if (i < 10) {
        std::cout << "|" << DecideWhichSlaveForTable2Day2(i - 1) << "         |"
                  << " " << 200 + (k - 26) * 2 + i << "\n";
      }
      if (i >= 10) {
        std::cout << "|" << DecideWhichSlaveForTable2Day2(i - 1) << "         |"
                  << " " << 200 + (k - 26) * 2 + i << "\n";
      }
    }
    std::cout << "------------------------------\n\n";

    std::cout << "Жив ли раб 1?";
    bool slave1 = !correctInputD();

    int result = findRightBarrelInput26to30(slave1, k);
    return result;
  }
  return -1;
}

int main() {
  intro();
  Day0();
  Day1intro();
  PrintTableDay1();
  int k = correctInputk();
  int result = Day2(k);
  std::cout << result;
  return 0;
}