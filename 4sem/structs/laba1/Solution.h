#pragma once
#include <iostream>

class Solution {
private:
    bool digitInNumber(int digit, long long int number) {
        if (digit == 0 && number == 0)
            return true;
        for (int d = number % 10; number > 0; number /= 10, d = number % 10)
            if (d == digit)
                return true;
        return false;
    }

    int countNumbersWithUniqueDigits(int n, long long int number) {
        if (n == 0)
            return 0;
        if (n < 0) {
            std::cerr << ">:0 ERROR!!!!! (n < 0)\n";
            return -1;
        }
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            if (!digitInNumber(i, number))
                sum += 1 + countNumbersWithUniqueDigits(n - 1, number * 10 + i);
        }
        return sum;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        return 1 + countNumbersWithUniqueDigits(n, 0);
    }
};

/*
Посчитать количество уникальных чисел от 0 включительно до 10^n не включительно.
Уникальным числом называют число, в котором ни одна цифра не повторяется.
34 - уникальное, 565 - не уникальное
*/
