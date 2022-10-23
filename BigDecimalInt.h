// FCAI – OOP – 2022 - Assignment 1
// Program: BigDecimalInt Class
// Author: Abdallah Hussein Ibrahim Hussein - Ahmad Reda Bayoumi - Esraa Mahmoud Abdelmohsen
// IDs: 20210235 - 20210019 - 20210063
// Date: October  2022
// ...........................................................................................

#ifndef BIGDECIMALINT_H_
#define BIGDECIMALINT_H_

#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

bool mark = true;
class BigDecimalInt
{
private:
	vector<int> num;
	string str;
	char str_sign = '+';

public:
	BigDecimalInt(string decStr);
	BigDecimalInt(int decInt);
	BigDecimalInt operator+(BigDecimalInt secondDec);
	string get_str();
	BigDecimalInt operator-(BigDecimalInt secondDec);
	bool operator<(BigDecimalInt secondDec);
	bool operator>(BigDecimalInt secondDec);
	bool operator==(BigDecimalInt secondDec);
	BigDecimalInt operator=(BigDecimalInt secondDec);
	int size();
	int sign();
	friend ostream &operator<<(ostream &out, BigDecimalInt secondDec);
};

#endif