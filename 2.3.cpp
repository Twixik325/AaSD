/*3.	Самостоятельно написать коды функций: 
•	Вывод линейного списка на экран
•	Поиск элемента линейного списка по его значению
•	Поиск элемента линейного списка по его порядковому номеру
•	Подсчет и вывод на экран количества звеньев в построенном Вами линейном списке
•	Построение кольцевого списка
•	Вывод на консоль кольцевого списка
•	Все функции объединить в единый листинг с помощью меню.
*/
#include <iostream>
using namespace std;
// Структура для элемента списка
struct Node {
    int data;
    Node* next;
};
// Функция для вставки элемента в начало списка
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// Функция для вывода списка на экран
void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
// Функция для поиска элемента по значению
Node* searchByValue(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value)
            return current;
        current = current->next;
    }
    return nullptr; // Элемент не найден
}
// Функция для поиска элемента по порядковому номеру
Node* searchByPosition(Node* head, int position) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == position)
            return current;
        current = current->next;
        count++;
    }
    return nullptr; // Элемент не найден
}
// Функция для подсчета и вывода количества элементов в списке
void countAndDisplay(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    cout << "Количество элементов в списке: " << count << endl;
}
// Функция для построения кольцевого списка
void makeCircular(Node* head) {
    if (head == nullptr) return;
    Node* current = head;
    while (current->next != nullptr)
        current = current->next;
    current->next = head; // Сделать последний элемент ссылкой на первый
}
// Функция для вывода кольцевого списка
void displayCircular(Node* head) {
    if (head == nullptr) return;
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    Node* head = nullptr; // Указатель на первый элемент списка
    int choice;
    int value;
    Node* foundNode;
    do {
        cout << "\nВыберите операцию:\n"
            << "1. Вставить элемент\n"
            << "2. Вывести список\n"
            << "3. Поиск элемента по значению\n"
            << "4. Поиск элемента по порядковому номеру\n"
            << "5. Подсчет и вывод количества элементов\n"
            << "6. Построить кольцевой список\n"
            << "7. Вывести кольцевой список\n"
            << "0. Выйти\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите значение: ";
            cin >> value;
            insert(head, value);
            break;
        case 2:
            cout << "Список: ";
            display(head);
            break;
        case 3:
            cout << "Введите значение для поиска: ";
            cin >> value;
            foundNode = searchByValue(head, value);
            if (foundNode != nullptr)
                cout << "Элемент найден: " << foundNode->data << endl;
            else
                cout << "Элемент не найден\n";
            break;
        case 4:
            int position;
            cout << "Введите порядковый номер для поиска: ";
            cin >> position;
            foundNode = searchByPosition(head, position);
            if (foundNode != nullptr)
                cout << "Элемент найден: " << foundNode->data << endl;
            else
                cout << "Элемент не найден\n";
            break;
        case 5:
            countAndDisplay(head);
            break;
        case 6:
            makeCircular(head);
            cout << "Кольцевой список построен\n";
            break;
        case 7:
            cout << "Кольцевой список: ";
            displayCircular(head);
            break;
        case 0:
            cout << "Программа завершена\n";
            break;
        default:
            cout << "Неверный ввод\n";
        }
    } while (choice != 0);
    // Освобождение памяти
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
