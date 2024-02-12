#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int rows, cols;
    cout << "Введите количество строк" << endl;
    cin >> rows;
    cout << "Введите количество столбцов" << endl;
    cin >> cols;

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 200 - 100;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int MaxABS = abs(arr[0][0]);
    int AbsRow = 0;
    int AbsCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int absValue = abs(arr[i][j]);
            if (absValue > MaxABS) {
                MaxABS = absValue;
                AbsRow = i;
                AbsCol = j;
            }
        }
    }
    cout << "Наибольший по модулю элемент матрицы: " << arr[AbsRow][AbsCol] << endl;
    cout << "Индексы этого элемента: [" << AbsRow + 1 << "][" << AbsCol + 1 << "]" << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
