#include "HashTable.h"

void HashTable::reHash() {
	a.clear();
	sizeTable *= 2;
	a.resize(sizeTable);
	fillingTable();
	cout << "коэффициент нагрузки хеш-таблицы = " << (double)count / (double)sizeTable << endl;
}

void HashTable::deleteNote(string key) {
	long hashIndex = hash(key);
	list <Polis*> ::iterator it = a[hashIndex].begin();
	
	if (it == a[hashIndex].end())
	{
		cout << "Такой записи нет" << endl;
		return;
	}
	ifstream f1("Polisa.txt"); // чтение 
	ofstream f2("Help.txt"); // запись
	string q,q1;
	q1 = (*it)->getNum() + "/" + (*it)->getKmp() + "/" + (*it)->getSurname() + "/"; // строка, которую нужно удалить 
	getline(f1, q); // строка из файла
	if (q != q1) 
		f2  << q;
	while (!f1.eof())
	{
		getline(f1, q);
		if (q != q1)
			f2 << endl << q;
	}
	f1.close();
	f2.close();
	f1.open("Help.txt");
	f2.open("Polisa.txt");
	getline(f1, q);
	f2 << q;
	while (!f1.eof())
	{
		getline(f1, q);
		f2 << endl << q;
	}
	f1.close();
	f2.close();
	a[hashIndex].erase(it);
	count -= 1;
	cout << "Удаление записи по ключу " << key << " произошло успешно." << endl;
}

Polis* HashTable::find(string key) {
	long hashIndex = hash(key);
	list <Polis*> ::iterator it = a[hashIndex].begin();
	while (it != a[hashIndex].end()) {
		if ((*it)->getNum() == key) 
			return (*it);
		it++;
	}
	return nullptr; // если запись не была найдена
}

void HashTable::add(Polis* ad) {
	a[hash(ad->getNum())].push_front(ad);
}

long HashTable::hash(string key) {
	long hashIndex = 7;
	for (int i = 0; i < key.length(); i++)   
		hashIndex = (hashIndex * 31 + (int)key[i]) % sizeTable;
	return hashIndex;
} 

void HashTable::fillingTable() {
	ifstream f;
	f.open("polisa.txt");
	int numberRecords = 0, j = 0;
	string stringInFile;
	string* del = new string[3]; // массив для трех строк - номер, компания, фамилия
	while (!f.eof()) {
		numberRecords++;
		getline(f, stringInFile);
		while (stringInFile.find("/") != -1)
		{
			del[j] = stringInFile.substr(0, stringInFile.find("/"));
			stringInFile.erase(0, stringInFile.find("/") + 1);
			j++;
		}
		Polis* p = new Polis(del[0], del[1], del[2], numberRecords);
		add(p);
		j = 0;
	}
	count = numberRecords;
	f.close();
}

HashTable::HashTable() {
	a.resize(sizeTable);
	fillingTable();
	setlocale(LC_ALL, "russian");
	string Y_N = " ";
	if ((double)count / (double)sizeTable >= 0.75) {
		cout << "Требуется рехеширование, так как коэффициент нагрузки больше или равен 0.75. Коэффициент нагрузки хеш-таблицы = " <<
			(double)count / (double)sizeTable <<
			endl << "Произвести рехеширование?(Y - да, N - нет): ";
		cin >> Y_N;
	}
	if (Y_N == "Y")
		while ((double)count/(double)sizeTable >= 0.75) // рехеширование
		{
			a.clear();
			sizeTable *= 2;
			a.resize(sizeTable);
			fillingTable();
		}
	cout << "коэффициент нагрузки хеш-таблицы = " << (double)count / (double)sizeTable << endl;
};

void HashTable::outTable() {
	list <Polis*> ::iterator it;
	for (int i = 0; i < sizeTable; i++) { // пройдем весь вектор
		if (!a[i].empty()) // если список не пуст 
		{
			cout << "Индекс хеш-таблицы: " << i << endl << "ключи:";
			 it = a[i].begin();
			 while (it != a[i].end()) { // проходим список через итераторы
				 cout << " " << (*it)->getNum(); // выводим номера
				 it++;
			 }
			 cout << endl;
		}
	}
}