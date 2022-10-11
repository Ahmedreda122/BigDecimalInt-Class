#include "BigDecimalInt.h"

bool mark = true;

BigDecimalInt::BigDecimalInt(string decStr)
{
	// TODO: 000005656565 remove zeros until number bigger than 0 //done
	// TODO: + / - remove signs in the begin of string //done
	// TODO: push the remaining into num vector //done
	/*
	TODO: use this old code
	// removing the spaces from the text to the end of it, then returning a pointer to the beginning of the removed spaces
	auto removed = remove(txt.begin(), txt.end(), ' ');
	// Erasing the spaces from the end of the text
	txt.erase(removed, txt.end());
	*/
	int cursor = 0;
	bool streak = true;

	if (decStr[0] == '+' || decStr[0] == '-')
	{
		mark = false;

		str_sign = decStr[0];
		// Erasing the first character in the String
		// Where 0 is the first character index, 1 is the number of characters we need to remove from that index.
		decStr.erase(0, 1);
	}
	else if (!isdigit(decStr[0]))
	{
		cout << "Invalid String";
		return;
	}

	if (decStr == "0")
	{
		num.push_back(0);
		return;
	}

	for (int i = 0; i < decStr.size(); ++i)
	{
		if (!isdigit(decStr[i]))
		{
			cout << "Invalid String";
			return;
		}

		if (decStr[i] == '0' && streak == true)
		{
			++cursor;
		}
		else
		{
			streak = false;
		}
	}

	if (cursor > 0)
	{
		// Erasing zeros from the beginning of the string, "cursor" of times
		decStr.erase(0, cursor);
	}

	str = decStr;

	for (int i = decStr.size() - 1; i >= 0; --i)
	{
		num.push_back((int)decStr[i] - (int)'0');
	}
}

BigDecimalInt::BigDecimalInt(int decInt)
{
	string decStr = to_string(decInt);

	if (decStr[0] == '+' || decStr[0] == '-')
	{
		mark = false;

		str_sign = decStr[0];
		// Erasing the first character in the String
		// Where 0 is the first character index, 1 is the number of characters we need to remove from that index.
		decStr.erase(0, 1);
	}

	str = decStr;

	for (int i = decStr.size() - 1; i >= 0; --i)
	{
		num.push_back((int)decStr[i] - (int)'0');
	}
}

void BigDecimalInt::show()
{
	for (int i = num.size() - 1; i >= 0; --i)
	{
		cout << num[i];
	}
}

string BigDecimalInt::get_str()
{
	if (str_sign == '-')
	{
		return ("-" + str);
	}
	return str;
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt secondDec)
{

	// vec[1,2,1] -> 121 , vec[1,9,2] -> 291
	//  121
	//+ 291
	//  (3+1)12 -> 412
	string result;
	int size;
	bool isNgtiv = false;

	// Make Both number at the same size
	while (num.size() < secondDec.num.size() || secondDec.num.size() < num.size())
	{
		if (num.size() < secondDec.num.size())
		{
			num.push_back(0);
		}
		else if (secondDec.num.size() < num.size())
		{
			secondDec.num.push_back(0);
		}
	}
	// make a place for carries just in case
	num.push_back(0);
	secondDec.num.push_back(0);

	// size of numbers to loop into it
	size = num.size();

	// Array to store the result
	int res[size];
	// fill array with zeros
	fill(res, res + size, 0);

	if (str_sign == '+' && secondDec.str_sign == '+')
	{
		for (int i = 0; i < size; ++i)
		{
			result = to_string(num[i] + secondDec.num[i]);
			// If result > 9 so we need to make carrier into the next element
			if (result.size() > 1)
			{
				// Ones position of the result will be in the current index
				res[i] += ((int)result[1] - (int)'0');
				// Tens position of the result will be in the next index
				res[i + 1] += ((int)result[0] - (int)'0');
			}
			// If result < 9 so we just plusing the result with the number in current index
			else
			{
				res[i] += ((int)result[0] - (int)'0');
			}
		}
	}
	else if (str_sign == '+' && secondDec.str_sign == '-')
	{
		for (int i = 0; i < size; ++i)
		{
			/*
			Want to flip the larger number to be in first place and just adding -ve sign in the end
			if (num < secondDec)
			{
					vector<int> temp = num;
					num = secondDec.num;
					secondDec.num = temp;
					isNgtiv = true;
			}
			*/
			// if ((num[i] - secondDec.num[i]) < 0 )
			// {
			// 	vector<int> temp = num;
			// 	num = secondDec.num;
			// 	secondDec.num = temp;
			// 	isNgtiv = true;
			// }
		
			if ((num[i] - secondDec.num[i]) < 0)
			{
				int j = i + 1;
				while (num[j] == 0)
				{ // 3999910
					if (num[j + 1] == 0)
					{
						num[j] = 9;
						++j;
					}
					else
					{
						num[j] = 9;
						num[j + 1]--;
						num[i] += 10;
						result = to_string(num[i] - secondDec.num[i]);
						res[i] = stoi(result);
					}
				}
			}
			else
			{
				result = to_string(num[i] - secondDec.num[i]);
				res[i] = stoi(result);
			}
		}
	}

	// String to hold the result
	string holder = "";

	for (int i = size - 1; i >= 0; --i)
	{
		holder += to_string(res[i]);
	}

	if (isNgtiv == true)
	{
		holder = "-" + holder;
	}

	// Returning the result in form of BigDecimalInt using string constructor
	return BigDecimalInt(holder);
}

bool BigDecimalInt::operator>(BigDecimalInt secondDec)
{
	int NumOfDigits1 = str.size();
	int NumOfDigits2 = secondDec.get_str().size();

	if (NumOfDigits1 > NumOfDigits2)
	{
		return true;
	}
	else if (NumOfDigits1 < NumOfDigits2)
	{
		return false;
	}
	else if (NumOfDigits1 == NumOfDigits2)
	{
		return (str > secondDec.get_str());
	}
}

bool BigDecimalInt::operator==(BigDecimalInt secondDec)
{
	return (str == secondDec.get_str());
}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt secondDec)
{
	str = secondDec.get_str();
	return BigDecimalInt(str);
}

int BigDecimalInt::size()
{
	return str.size();
}

int BigDecimalInt::sign()
{
	if (str_sign == '+')
	{
		return 1;
	}
	else if (str_sign == '-')
	{
		return -1;
	}
	else
	{
		// Must return something in any case
		return 0;
	}
}

ostream &operator<<(ostream &out, BigDecimalInt secondDec)
{
	if (mark) // user didn't enter a sign
	{
		out << secondDec.get_str();
	}
	else // user enters a sign
	{
		out << secondDec.str_sign << secondDec.get_str();
	}
	return out;
}
//...^_^...//