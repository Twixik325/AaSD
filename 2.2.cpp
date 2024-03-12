/*2.	На основе алгоритмов из лекции 2, созданных с помощью схем Дональда Кнута, написать соответствующие коды функций с комментариями и реализовать их в редакторе кода:  
•	int Vstav (int el) - вставка после звена, на которое направлен указатель.
•	void Ydale (node *Res, node*t) - удаление после звена, на которое направлен указатель. 
*/
#include <iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};

int main() {
	node* phead;     //стационарный указатель на заглавное звено 
	node* t, * Res;   //перемещающиеся рабочие указатели на текущие звенья 
	int el;
}
int Vstav(int el)
{
	node* t, * Res;
	int sch;

	cout << "**Вставка элемента после искомого элемента**" << endl;
	node* t;
	cout << "Введите значение вставляемого элемента в список: " << endl;
	cin >> el;
	t = new(node);
	(*t).value = el;
	(*t).next = (*Res).next;
	sch = sch + 1; //подсчет количества элементов в списке
	cout << "значение sch:  " << sch << endl;
	return el;
}
void Ydale(node* Res, node* t, int el)
{
	int sch;
	cout << "Удаление элемента : " << el << endl;
	t = (*Res).next;
	if (t != NULL)//Если звено, после которого нужно удалять, не является последним, то...
	{
		(*Res).next = ((*(*Res).next).next);
		delete t;
		sch -= 1;
		cout << "значение sch:  " << sch << endl;
	}
	else
		cout << "Звено с заданным элементом - последнее!\n";
}
