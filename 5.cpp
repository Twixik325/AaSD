#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int N;
    cout << "Введите порядок Матрицы" << endl;
    cin >> N;

    int** arr = new int* [N];

    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Введите " << "[" << i+1 << "]" << "[" << j+1 << "] элемент ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int MinRow;
    int MinCol;
    int MinValue = INT_MAX;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] < MinValue) {
                MinValue = arr[i][j];
                MinRow = i;
                MinCol = j;
            }
        }
    }

    int sum = 0;
    for (int j = 0; j < N; ++j) {
        sum += arr[MinRow][j];
    }

    cout << "Строка с минимальным элементом: ";
    for (int j = 0; j < N; ++j) {
        cout << arr[MinRow][j] << " ";
    }
    cout << endl;
    cout << "Сумма элементов этой строки: " << sum << endl;

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
