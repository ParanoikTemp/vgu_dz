#include <iostream>
#include <cmath>

/*
 * Числа Фибоначчи - элементы числовой последовательности, в которой первые два числа равны 0 и 1,
 * а каждое последующее число равно сумме двух предыдущих чисел. Можно заметить, что при рекурсивном
 * вычислении очередного члена последовательности одно и то же число вычисляется два раза.
 * Требуется написать функцию, которая получает на вход целое число N, которое вводится с клавиатуры
 * и выводит на экран N-ное число Фибоначчи, при этом решив проблему повторных вычислений.
 * Кроме того, если на очередной итерации введено число N, меньшее, чем на одном из предыдущих шагов,
 * ответ должен быть получен за О(1). Функция продолжает запускаться неограниченное количество раз до
 * тех пор, пока с клавиатуры не будет введен 0
 */

struct HTNode {
    int key;
    long long value;
};

class HT {
private:
    int length;
    HTNode **nodes;
public:
    HT() {
        length = 3;
        nodes = new HTNode*[length];
        nodes[0] = new HTNode{0, 0};
        nodes[1] = new HTNode{1, 1};
        nodes[2] = new HTNode{1, 1};
    }

    bool has(int key) {
        return key < length && nodes[key];
    }

    long long get(int key) const {
        return nodes[key]->value;
    };

    void add(int key, long long value) {
        if (key + 1 > length) {
            HTNode **nodes2 = nodes;
            nodes = new HTNode*[key + 1];
            for (int i = 0; i < length; ++i)
                nodes[i] = nodes2[i];
            for (int i = length; i < key; ++i)
                nodes[i] = nullptr;
            nodes[key] = new HTNode{key, value};
            length = key + 1;
            delete[] nodes2;
        } else {
            if (nodes[key])
                delete nodes[key];
            nodes[key] = new HTNode{key, value};
        }
    }
};

long long fibo(int n) {
    static HT hash;
    bool sub = n < 0;
    if (sub) n *= -1;
    if (hash.has(n)) {
        if (sub)
            return hash.get(n) * (int) std::pow(-1, n + 1);
        else
            return hash.get(n);
    }
    else {
        if (!hash.has(n - 1))
            fibo(n - 1);
        if (!hash.has(n - 2))
            fibo(n - 2);
        long long res = hash.get(n - 1) + hash.get(n - 2);
        hash.add(n, res);
        if (sub)
            return res * (int) std::pow(-1, n + 1);
        else
            return res;
    }
}


int main() {
    // нумерацию чисел (включая отрицательные n) в последовательности я позаимствовал в Википедии
    int n;
    bool run = true;
    while (run) {
        std::cin >> n;
        if (!n) run = false;
        else
            std::cout << fibo(n) << std::endl;
    }
    return 0;
}
