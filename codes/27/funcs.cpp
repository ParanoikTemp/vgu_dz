#include "funcs.h"

void convertFiles(const string& inputFile, const string& outputFile)
{
    ifstream inFile(inputFile);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile)
    {
        cout << "Ошибка открытия файла " << inputFile << endl;
        return;
    }

    if (!outFile)
    {
        cout << "Ошибка открытия файла " << outputFile << endl;
        return;
    }

    Book book;
    while (inFile.getline(book.author, 41, '|') &&
           inFile.getline(book.title, 81, '|') &&
           inFile.getline(book.year, 5, '|') &&
           inFile.getline(book.specialization, 41))
    {
        outFile.write((char*)&book, sizeof(book));
    }

    inFile.close();
    outFile.close();
}

void processBinaryFile(const string& fileName)
{
    ifstream inFile(fileName, ios::binary);

    if (!inFile)
    {
        cout << "Ошибка открытия файла " << fileName << endl;
        return;
    }
    Book book;
    char specialization[41];
    int* numbers = new int[1];
    char** specializations = new char*[1];
    specializations[0] = new char[41];
    int count = 1;
    while (inFile.read((char*)&book, sizeof(book)))
    {
        bool found = false;
        strcpy(specialization, book.specialization);

        for (int i = 0; i < count; i++)
        {
            if (strcmp(specialization, specializations[i]) == 0)
            {
                numbers[i]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            int* tempNumbers = new int[count + 1];
            char** tempSpecializations = new char*[count + 1];

            for (int i = 0; i < count; i++)
            {
                tempNumbers[i] = numbers[i];
                tempSpecializations[i] = specializations[i];
            }

            tempNumbers[count] = 1;
            tempSpecializations[count] = new char[41];
            strcpy(tempSpecializations[count], specialization);

            delete[] numbers;
            delete[] specializations;

            numbers = tempNumbers;
            specializations = tempSpecializations;
            count++;
        }
    }
    // for (int i = 1; i < count; i++) cout << specializations[i] << " " << numbers[i] << endl;
    int maxIndex = 0;
    for (int i = 1; i < count; i++)
    {
        if (numbers[i] > numbers[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << "Специальность с наибольшим числом: " << specializations[maxIndex] << endl;

    delete[] numbers;
    for (int i = 0; i < count; i++)
    {
        delete[] specializations[i];
    }
    delete[] specializations;

    inFile.close();
}

