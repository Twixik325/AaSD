/*В одномерном массиве, состоящем из n вещественных чисел, вычислить: 
а) количество элементов массива, меньших С; 
б) сумму положительных элементов, расположенных после первого положительного элемента. 
Преобразовать массив таким образом, чтобы сначала располагались все элементы, целая часть которых лежит в интервале [a, b], а потом – все остальные.
*/
#include <iostream>
#include <cstdlib>
#include <locale>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n, index;
	float C, a, b;
	int num = 0;
	bool F = false;
	float sum = 0;
	cout << "Введите число элементов" << endl;
	cin >> n;
	cout << "Введите число C" << endl;
	cin >> C;
	cout << "Введите число a" << endl;
	cin >> a;
	cout << "Введите число b" << endl;
	cin >> b;
	float* arr = new float[n];
	float* arr2 = new float[n];
	index = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10 + (rand() % 10) * 0.1 +(rand() % 10) * 0.01;
		if (arr[i] < C) num++;
		if (arr[i] > 0) F = true;
		if (F && arr[i] > 0) sum += arr[i];
		if (arr[i] <= b && arr[i] >= a) {
			arr2[index] = arr[i];
			index++;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Элементов массива меньше C("<< C << "): " << num << endl;
	cout << "Сумма положительных элементов массива после первого: "<< sum << endl;
	cout << "Массив чисел в интервале ["<< a << ", "<< b << "]:" << endl;
	for (int i = 0; i < index; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}
