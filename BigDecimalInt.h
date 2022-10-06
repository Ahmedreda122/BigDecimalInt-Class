#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm> // std::for_each

using namespace std;

class BigDecimalInt
{
private:
	vector<int> num;
	string str;
	char str_sign = '+';

public:
	BigDecimalInt(string decStr);
	BigDecimalInt(int decInt);
	string get_str();
	// int get_int();
	BigDecimalInt operator+(BigDecimalInt secondDec);
	bool operator>(BigDecimalInt secondDec);
	bool operator==(BigDecimalInt secondDec);
	BigDecimalInt operator=(BigDecimalInt secondDec);
	int size();
	int sign();
	friend ostream& operator<<(ostream& out, BigDecimalInt secondDec);
};