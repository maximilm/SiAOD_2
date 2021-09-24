#pragma once
#include "Polis.h"
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class HashTable {
private:

	long sizeTable = 10000;  // размер хеш таблицы по умолчанию 10000
	vector<list<Polis*>> a; // запись в которой содержится список. Список хранит указатели на объекты класса Polis
	list <Polis*> ::iterator it; // итератор, чтобы перемещаться по списку
	long count = 0; // количество записей в хеш таблице

public:

	HashTable();
	void add(Polis* ad);
	void deleteNote(string key);
	long hash(string k);
	void fillingTable();
	void reHash();
	Polis* find(string p);
	void outTable();
};