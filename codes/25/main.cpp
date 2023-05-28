#include "listcode.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RU");
    double nums[] = {1, 2, 4, 8, 16, 32, 64};
    Node* list = makeList(nums, 7);
    cout << "Арифметическая прогрессия " << (isArithmeticProgression(list) ? "присутствует" : "отсутствует") << endl;
    cout << "Геометрическая прогрессия " << (isGeometricProgression(list) ? "присутствует" : "отсутствует") << endl;
    return 0;
}
