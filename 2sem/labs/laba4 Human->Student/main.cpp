#include "Student.h"

void printer(Student mn) {
    mn.print();
}

int main() {
    Student* st = new Student("Igor", 18, false, 78, 2022);
    printer(*st);
    st->setAge(19);
    printer(*st);
    Student kek("Anton", 24, false, 66, 2023);
    printer(kek);
    kek = *st;
    st->setAge(20);
    printer(kek);
    return 0;
}
