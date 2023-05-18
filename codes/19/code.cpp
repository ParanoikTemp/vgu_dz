#include "code.h"

void createBinFile(const string& input, const string& output) {
    ifstream inputfile(input);
    ofstream outputfile(output, ios::binary);
    if (inputfile.is_open() && outputfile.is_open()) {
        int i;
        string line;
        Student pattern{"Noname", 1, 1, true};
        Exam exam;
        while (getline(inputfile, line)) {
            Student student{};
            stringstream words(line);
            getline(words, line, '|');
            if (!line.empty()) for (int k = 0; k < line.length(); ++k) student.fio[k] = line[k];
            else for (int k = 0; k < 41; ++k) student.fio[k] = pattern.fio[k];
            getline(words, line, '|');
            student.course = !line.empty() ? stoi(line) : 1;
            getline(words, line, '|');
            student.group = !line.empty() ? stoi(line) : 1;
            getline(words, line, '|');
            student.education = line == "c";
            i = 0;
            while (!words.eof()) {
                getline(words, line, '|');
                student.exams[i].mark = !line.empty() ? stoi(line) : 0;
                getline(words, line, '|');
                if (!line.empty()) for (int k = 0; k < line.length(); ++k) student.exams[i].object[k] = line[k];
                else for (int k = 0; k < 11; ++k) student.exams[i].object[k] = exam.object[k];
                ++i;
            }
            outputfile.write((char*)&student, sizeof (student));
        }
        inputfile.close();
        outputfile.close();
    } else {
        cout << "Оно не работает(((((((";
        raise(1);
    }
}

void createFinalFile(const string& input, const string& output) {
    ifstream inputfile(input, ios::binary);
    ofstream outputfile(output);
    bool flag;
    if (inputfile.is_open() && outputfile.is_open()) {
        while (!inputfile.eof()) {
            Student golodniy{};
            inputfile.read((char*)&golodniy, sizeof(golodniy));
            if (golodniy.course == 0) break;
            flag = true;
            for (int i = 0; i < 50; ++i) {
                if (golodniy.exams[i].mark == 2) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                outputfile << golodniy.fio << "|" << golodniy.course << "|" << golodniy.group << '|' << ((golodniy.education) ? 'c' : 'd') << '|';
                for (int i = 0; i < 50; ++i) {
                    if (golodniy.exams[i].mark != 0) {
                        outputfile << golodniy.exams[i].mark << '|' << golodniy.exams[i].object << '|';
                    } else {
                        outputfile << '\n';
                        break;
                    }
                }
            }
        }
        inputfile.close();
        outputfile.close();
    } else {
        cout << "Да ну вас(((((((";
        raise(1);
    }
}