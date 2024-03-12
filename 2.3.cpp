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

// Класс для линейного списка
class LinkedList {
private:
    Node* head; // Указатель на первый элемент списка
public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор для освобождения памяти
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Вставка элемента в начало списка
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Вывод списка на экран
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Поиск элемента по значению
    Node* searchByValue(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr; // Элемент не найден
    }

    // Поиск элемента по порядковому номеру
    Node* searchByPosition(int position) {
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

    // Подсчет и вывод количества элементов в списке
    void countAndDisplay() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        cout << "Количество элементов в списке: " << count << endl;
    }

    // Построение кольцевого списка
    void makeCircular() {
        if (head == nullptr) return;
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = head; // Сделать последний элемент ссылкой на первый
    }

    // Вывод кольцевого списка
    void displayCircular() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
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
            list.insert(value);
            break;
        case 2:
            cout << "Список: ";
            list.display();
            break;
        case 3:
            cout << "Введите значение для поиска: ";
            cin >> value;
            foundNode = list.searchByValue(value);
            if (foundNode != nullptr)
                cout << "Элемент найден: " << foundNode->data << endl;
            else
                cout << "Элемент не найден\n";
            break;
        case 4:
            int position;
            cout << "Введите порядковый номер для поиска: ";
            cin >> position;
            foundNode = list.searchByPosition(position);
            if (foundNode != nullptr)
                cout << "Элемент найден: " << foundNode->data << endl;
            else
                cout << "Элемент не найден\n";
            break;
        case 5:
            list.countAndDisplay();
            break;
        case 6:
            list.makeCircular();
            cout << "Кольцевой список построен\n";
            break;
        case 7:
            cout << "Кольцевой список: ";
            list.displayCircular();
            break;
        case 0:
            cout << "Программа завершена\n";
            break;
        default:
            cout << "Неверный ввод\n";
        }
    } while (choice != 0);

    return 0;
}
