/*Дан одномерный массив.Написать функцию, определяющую минимальный, максимальный элементы массива и среднее арифметическое минимального и максимального элементов.
Кроме того, программа должна иметь функцию ввода одномерного массива и функцию вывода.*/
#include <iostream>
#include <cstdlib>
#include <locale>
#include <ctime>

using namespace std;

void func(int* arr, int n) {
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
	cout << "Минимальный элемент " << min << endl;
	cout << "Максимальный элемент " << max << endl;
	average = (min + max) / 2.0;
	cout << "Среднее Арифметическое " << average << endl;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите число элементов" << endl;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
	}
	func(arr, n);

	delete[] arr;
	return 0;
}
