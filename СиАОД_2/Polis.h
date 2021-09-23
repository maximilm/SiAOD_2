#pragma once
#include <iostream>
#include <string>
using namespace std;
class Polis {
private:
	string num;
	string kmp;
	string surname;
	long numInFile;
public:
	Polis(string num, string kmp, string surname, long numInFile) {
		this->num = num;
		this->kmp = kmp;
		this->surname = surname;
		this->numInFile = numInFile;
	}
	string getNum() {
		return num;
	}
	string getKmp(){
		return kmp;
	}
	string getSurname(){
		return surname;
	}
	long  getNumInFile() {
		return numInFile;
	}
};