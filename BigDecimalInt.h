#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <ctype.h> 
#include <algorithm>    // std::for_each

using namespace std;

class BigDecimalInt
{
private:
	vector<int> num;
	char sign = '+';

public:
	BigDecimalInt(string decStr);
	BigDecimalInt(int decInt);
	BigDecimalInt operator+(BigDecimalInt secondDec);
};