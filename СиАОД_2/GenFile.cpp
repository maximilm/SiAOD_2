#include "GenFile.h"

void genFile(int n) { // ������� ���������� ����� ��������
	setlocale(LC_ALL, "russian");
	locale::global(locale(".utf8"));
	srand(time(0));
	ofstream f;
	f.open("polisa.txt");
	f << genRandomDigits(8) << "/" << genRandomLetter(4) << "/" << genRandomLetter(8) << "/";
	for (int i = 1; i < n; i++) {
		f << endl << genRandomDigits(8) << "/" << genRandomLetter(4) << "/" << genRandomLetter(8) << "/";
	}
	f.close();
}

string genRandomLetter(const int len) { // ������� ������� ���  ��� �������� 
	string tmp_s;
	static const char alphanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	tmp_s.reserve(len);
	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;
}

string genRandomDigits(const int len) { // ������� ������� ��� ����� ���������� ������
	string tmp_s;
	static const char alphanum[] =
		"0123456789";
	tmp_s.reserve(len);
	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;
}