#include <iostream>
#include "calculations.h"

int main() {
  int m, n;
  std::cout << "Введите m и n: ";
  std::cin >> m >> n;
  
  int k = findMaxNum(m, n);
  std::cout << "Наибольшее число с суммой цифр как у " << m << " между " << m << " и " << n << ": " << k << std::endl;
  
  return 0;
}
