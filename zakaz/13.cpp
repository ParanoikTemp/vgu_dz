#include<iostream>
#include<string>

using namespace std;

int **newScorecard(int n, int m) {
    int **matrix = new int * [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int [m];
        for (int j = 0; j < m; ++j) matrix[i][j] = 2 + rand() % 4;
    }
    return matrix;
}

void printScorecard(int **scorecard, string *students, string *classes, int n, int m) {
    cout << "/\t"; for (int j = 0; j < m; ++j) cout << classes[j] << "\t"; cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << students[i] << "\t";
        for (int j = 0; j < m; ++j) cout << scorecard[i][j] << "\t";
        cout << endl;
    }
}

int *getStroke(int **matrix, int num) {
    return matrix[num - 1];
}

int *getColumn(int **matrix, int num, int n) {
    int *column = new int [n];
    for (int i = 0; i < n; ++i) column[i] = matrix[i][num - 1];
    return column;
}

float arithmeticMean(int *stroke, int m) {
    float sum = 0;
    for (int j = 0; j < m; ++j) sum += (float) stroke[j];
    return sum / (float) m;
}

int subjectMatterProgress(int *column, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) if (column[i] > 3) ++sum;
    return sum;
}

int main()
{
    int n, m;
    cout << "Enter the number of students: "; cin >> n; cout << endl;
    cout << "Enter the number of classes: "; cin >> m; cout << endl;
    string *students = new string [n], *classes = new string [m];
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        cout << "Enter the name of " << i + 1 << " student: ";
        getline(cin, students[i]);
        cout << endl;
    }
    for (int j = 0; j < m; ++j) {
        cout << "Enter the name of " << j + 1 << " class: ";
        getline(cin, classes[j]);
        cout << endl;
    }
    auto scorecard = newScorecard(n, m);
    char doing = '.';
    int num;
    while (doing != '-') {
        printScorecard(scorecard, students, classes, n, m);
        cout << "Select an action:\n"
                "Enter \"1\" to view the student's grade point average\n"
                "Enter \"2\" to see the number of successful students in this subject\n"
                "Enter \"-\" to end the program\n";
        cin >> doing;
        if (doing == '1') {
            for (int i = 0; i < n; ++i) cout << i + 1 << ") " << students[i] << endl;
            cout << "Enter the student number: "; cin >> num; cout << endl;
            float result = arithmeticMean(getStroke(scorecard, num), m);
            cout << "The average grade for the student \"" << students[num - 1] << "\" is: " << result << "\n\n";
        } else if (doing == '2') {
            for (int i = 0; i < m; ++i) cout << i + 1 << ") " << classes[i] << endl;
            cout << "Enter the subject number: "; cin >> num; cout << endl;
            int result = subjectMatterProgress(getColumn(scorecard, num, n), n);
            cout << "The number of successful students in the subject  \"" << classes[num - 1] << "\": " << result << "\n\n";
        }
    }
    return 0;
}
