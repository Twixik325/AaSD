#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <ctime>

using namespace std;

void func(int *arr,int n) {
	double average;
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Min Element: " << min << endl;
	cout << "Max Element: " << max << endl;
	average = (min + max) / 2.0;
	cout << "Average: " << average << endl;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Write the num of the elements" << endl;
	cin >> n; // Считываем количество элементов массива
	int* arr = new int [n]; // Выделяем память для массива
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10; // Заполняем массив случайными числами от 0 до 9
	}
	func(arr, n); // Вызываем функцию для обработки массива

	delete[] arr; // Освобождаем выделенную память
	return 0;
}
