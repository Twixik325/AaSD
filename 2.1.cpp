/*1.Реализовать рассмотренный в Лекции №2 готовый код функции построения линейного списка void Postroenie () в удобном для Вас редакторе кода на языке программирования С++.*/
//Функция построения однонаправленного списка
#include <iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};

    node* phead;     //стационарный указатель на заглавное звено 
int main() {
    node* t, * Res;   //перемещающиеся рабочие указатели на текущие звенья 
    int el;          //числовое значение информационного поля value


}
//Функция построения однонаправленного списка
void POSTROENIE()
{
    node* t;
    int el;
    cout << "**Построение однонаправленного списка**" << endl;
    // Создадим заглавное звено 
    phead = new (node);
    // Присвоим значение указателю t
    t = phead;
    // Присвоим указателю заглавного звена NULL
    (*t).next = NULL;
    //Организуем цикл построения списка до того момента, как пользователь не введет значение //ноль в информационное поле.
    cout << "Введите значения информационных полей звеньев списка: " << endl;
    cin >> el;
    while (el != 0)
    {
        //Резервируем место для нового звена.
        (*t).next = new (node);

        //Определяем t. Указатель t содержит адрес расположения нового звена.
        t = (*t).next;

        //Заполняем поля звена
        (*t).value = el; (*t).next = NULL;

        //Запрос на ввод следующего значения.
        cin >> el;
    }
}
