/*Написать функции вычисления суммы элементов каждой строки матрицы А размером 6х6, определения наибольшего значения этих сумм. */
#include <iostream>
#include <ctime>

using namespace std;

void Rowsum(int** arr, int n) {
    int maxSum = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        if (maxSum < sum) {
            maxSum = sum;
            index = i+1;
        }
    }
    cout << "Максимальная сумма элементов = " << maxSum << " под номером " << index << endl;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int rows = 6, cols = 6;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10 + 1;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    Rowsum(arr, 6);

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
