#include "calculations.h"

// Функция для подсчета суммы цифр числа
int digitSum(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

// Функция для нахождения наибольшего числа с той же суммой цифр между m и n
int findMaxNum(int m, int n) {
  int targetSum = digitSum(m);
  int result = -1;
  
  for (int i = m; i <= n; i++) {
    if (digitSum(i) == targetSum) {
      result = i;
    }
  }
  return result;
}
