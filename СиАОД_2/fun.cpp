#include <iostream>
#include <ctime>
#include <iomanip>
#include "fun.h"
#include "genText.h"
string gen_random(const int len) { // функция рандома для  ФИО студента 
	string tmp_s;
	static const char alphanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	tmp_s.reserve(len);
	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;
}
string gen_random1(const int len) { // функция рандома для номера группы, номера зачетной книжки 
	string tmp_s;
	static const char alphanum[] =
		"0123456789";
	tmp_s.reserve(len);
	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return tmp_s;
}
//vector <string> input(string s) { // делим данные из каждой строки 
//	vector <string> s1;
//	if (s.size() > 3) {
//		string delimiter = "/";
//		size_t pos = 0;
//		while ((pos = s.find(delimiter)) != std::string::npos) {
//			s1.push_back(s.substr(0, pos));
//			s.erase(0, pos + delimiter.length());
//		}
//	}
//	else {
//		for (int i = 0; i < 3; i++) {
//			s1.push_back("");
//		}
//	}
//	return s1;
//}
////string* FullIn(int n) { // создание таблицы с номерами зачетной книжки каждого студента 
////	ifstream f11;
////	f11.open("student.txt");
////	string* A = new string[n];
////	for (int i = 0; i < n; i++) {
////		string s2;
////		getline(f11, s2);
////		vector<string> s3 = input(s2);
////		A[i] = s3[0];
////	}
////	f11.close();
////	return A;
////};