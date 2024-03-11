/*Дана действительная матрица размера 6х9. Найти среднее арифметическое наибольшего и наименьшего значений ее элементов. */
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    int max, min;
    int rows = 6, cols = 9;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 200 - 100;
            max = arr[0][0];
            min = arr[0][0];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Максимальный элемент в массиве " << max << endl;
    cout << "Минимальный элемент в массиве " << min << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
