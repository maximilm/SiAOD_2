#include <iostream>
#include <vector>
#include "genFile.h"
#include "HashTable.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "russian"); 
    int capacity;
    cout << "Введите количество страховых полисов в файле: ";
    cin >> capacity;
    genFile(capacity);
    HashTable table;
    int comand; 
    cout << "1 - поиск записи по ключу;" << endl;
    cout << "2 - удаление записи по ключу; " << endl;
    cout << "3 - рехеширование таблицы;" << endl;
    cout << "4 - вывод хеш таблицы в консоль;" << endl;
    cout << "0 - выход." << endl;
    do {
        cout << "Введите номер функции: ";
        cin >> comand;
        string key;
        Polis* polis_test;
        switch(comand) {
        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            polis_test = table.find(key);
            if (polis_test == nullptr)
                cout << "записи по ключу " << key << " нет." << endl;
            else
                cout << "Страховой полис: " << endl 
                        << "Номер: " << polis_test->getNum() << endl 
                            << "Компания: " << polis_test->getKmp() << endl 
                                << "Фамилия владельца: " << polis_test->getSurname() << endl;
            break;
        case 2:
            cout << "Введите ключ: ";
            cin >> key;
            table.deleteNote(key);
            break;
        case 3:
            table.reHash();
            break;
        case 4:
            table.outTable();
            break;
        }
    } while (comand != 0);
    return 0;
}