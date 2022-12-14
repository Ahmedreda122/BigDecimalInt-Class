// FCAI – OOP – 2022 - Assignment 1
// Program: BigDecimalInt Class
// Author: Abdallah Hussein Ibrahim Hussein S22 - Ahmad Reda Bayoumi S22 - Esraa Mahmoud Abdelmohsen S7
// IDs: 20210235 - 20210019 - 20210063
// Date: October  2022
// ...........................................................................................

#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr)
{
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
		str = "0";
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
    if (decStr == "")
    {
      decStr = "0";
    }
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

string BigDecimalInt::get_str()
{
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
  else if (str_sign == '-' && secondDec.str_sign == '-')
  {
    return (BigDecimalInt("-" + str) - BigDecimalInt(secondDec.str));
  }
	else 
	{
		// A copy of this->num
		vector<int> thisNum = num;
		// The Default is str_sign == '+' && secondDec.str_sign == '-'
		// Fliping the larger number to be in first place and calculate the substraction
		// -200 + 500 => 500 - 200 = 300
		if ((str_sign == '-' && secondDec.str_sign == '+') && (BigDecimalInt(secondDec.get_str()) > BigDecimalInt(str)))
		{
			swap(thisNum, secondDec.num);
		}
		/*
			Just adding -ve sign in the end
			-600 + 200 => 600 - 200 => 400 => -400
		*/
		else if (str_sign == '-' && secondDec.str_sign == '+') // && (BigDecimalInt(thisStr) > BigDecimalInt(secondDec.get_str()))
		{
			isNgtiv = true;
		}
		// Fliping the larger number to be in first place and just adding -ve sign in the end
		// 200 + - 500 = 500 - 200 = 300 => -300
		else if (BigDecimalInt(secondDec.get_str()) > BigDecimalInt(str)) // && (str_sign == '+' && secondDec.str_sign == '-')
		{
			swap(thisNum, secondDec.num);
			isNgtiv = true;
		}

		for (int i = 0; i < size; ++i)
		{
			if ((thisNum[i] - secondDec.num[i]) < 0)
			{
				int j = i + 1;
        if (thisNum[j] == 0)
        {
          while (thisNum[j] == 0)
          { // 3999910
            if (thisNum[j + 1] == 0)
            {
              thisNum[j] = 9;
              ++j;
            }
            else
            {
              thisNum[j] = 9;
              thisNum[j + 1]--;
              thisNum[i] += 10;
              result = to_string(thisNum[i] - secondDec.num[i]);
              res[i] = stoi(result);
              break;
            }
          }
        }
				else if (thisNum[j] != 0)
				{
					thisNum[j]--;
					thisNum[i] += 10;
					result = to_string(thisNum[i] - secondDec.num[i]);
					res[i] = stoi(result);
				}
			}
			else
			{
				result = to_string(thisNum[i] - secondDec.num[i]);
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

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt secondDec)
{
	string result;
  string holder;
	int size;
	bool isNgtiv = false;

	// Make Both number at the same size
	while (num.size() < secondDec.num.size() || num.size() > secondDec.num.size())
	{
		if (num.size() < secondDec.num.size())
			num.push_back(0);
		else if (num.size() > secondDec.num.size())
			secondDec.num.push_back(0);
	}

	size = num.size();

	int finalR[size];
	// store largest number
	vector<int> max;
	// store smallest number
	vector<int> min;
	// fill array with zeros
	fill(finalR, finalR + size, 0);
	
	char sign1,sign2;
	// move largest number in max and smallest in min
  if (BigDecimalInt(str) > BigDecimalInt(secondDec.str))
	{
		for (int i = 0; i < size; i++)
		{
			max.push_back(num[i]);
			sign1 = str_sign;
			min.push_back(secondDec.num[i]);
			sign2 = secondDec.str_sign;
		}
		// if the sign of largest number is nigtv
		if (sign1 == '-' && sign2 == '+')
		{
      // -500 - 200
			isNgtiv = true;
      auto result = BigDecimalInt(str) + secondDec;
      result.str_sign = '-';
      return result;
		}
		// if the sign of smallest number is nigtv
		if (sign2 == '-'&& sign1 == '+')
		{
      // 500 -- 200
			return BigDecimalInt(str) + BigDecimalInt(secondDec.str);
		}
		if (sign1 == '-' && sign2 == '-' )
		{
			isNgtiv = true;
		}
	}
  else if (BigDecimalInt(str) < BigDecimalInt(secondDec.str))
	{
		for (int i = 0; i < size; i++)
		{
			max.push_back(secondDec.num[i]);
			sign1 = secondDec.str_sign;
      min.push_back(num[i]);
			sign2 = str_sign;
		}
		// if the sign of smallest number is nigtv
		if (sign2 == '-' && sign1 == '+')
		{
      //- 200 - 500
      auto result = BigDecimalInt(str) + secondDec;
      result.str_sign = '-';
      return result;
			return BigDecimalInt(str) + secondDec;
		}
		// if the sign of largest number is nigtv
		if (sign1 == '-' && sign2 == '+')
		{
      //200 - - 500
      return BigDecimalInt(str) + BigDecimalInt(secondDec.str);
		}
		if (sign2 == '-' && sign1 == '-')
		{
			isNgtiv = false;
		}
	}

	if ((str_sign == '-' && secondDec.str_sign == '-') || (str_sign == '+' && secondDec.str_sign == '+'))
	{
		for (int i = 0; i < size; i++)
		{
			if (max[i] < min[i])
			{
				max[i] += 10;
				finalR[i] = max[i] - min[i];
				int z = i;
				if (max[i + 1] == 0)
				{
					// borrow from the next number
					while (max[z + 1] == 0 && max[z + 1] != '\0')
					{
						max[z + 1] = 9;
						z++;
					}
					max[z + 1] -= 1;
				}
				else
          max[i + 1] -= 1;
			}

			else
			{
				finalR[i] = max[i] - min[i];
			}
		}
		// String to hold the result
		holder = "";

		for (int i = size - 1; i >= 0; --i)
		{
			holder += to_string(finalR[i]);
		}

		if (isNgtiv == true)
		{
			holder = "-" + holder;
		}
	}	
  // Returning the result in form of BigDecimalInt using string constructor
	return BigDecimalInt(holder);
}

bool BigDecimalInt::operator<(BigDecimalInt secondDec)
{
	int size1 = str.size();
	int size2 = secondDec.get_str().size();
	if ((str_sign != secondDec.str_sign))
	{
		if (str_sign == '-')
			return true;
		else if (secondDec.str_sign == '-')
			return false;
	}
	else if((str_sign == secondDec.str_sign))
	{
		if (size1 != size2)
		{
			if ((size1 > size2) && (str_sign == '+'))
				return false;
			else if ((size2 > size1) && (str_sign == '+'))
				return true;
			else if ((size1 > size2) && (str_sign == '-'))
				return true;
			else if ((size1 < size2) && (str_sign == '-'))
				return false;
		}
		else if (size1 == size2)
		{
			if (str_sign == '-')
			{
				return (str > secondDec.str);
			}
			else
			{
				return (str < secondDec.str);
			}
		}
	}
  return false;
}

bool BigDecimalInt::operator>(BigDecimalInt secondDec)
{
	int NumOfDigits1 = str.size();
	int NumOfDigits2 = secondDec.str.size();
	if (str_sign == '-' && secondDec.str_sign == '+')
	{
		return false;
	}
	else if (secondDec.str_sign == '-' && str_sign == '+')
	{
		return true;
	}
	else if ((NumOfDigits1 > NumOfDigits2) && str_sign == '+' && secondDec.str_sign == '+')
	{
		return true;
	}
	else if ((NumOfDigits1 < NumOfDigits2) && str_sign == '+' && secondDec.str_sign == '+')
	{
		return false;
	}
	else if ((NumOfDigits1 == NumOfDigits2) && str_sign == '+' && secondDec.str_sign == '+')
	{
		return (str > secondDec.get_str());
	}
	else if ((NumOfDigits1 > NumOfDigits2) && str_sign == '-' && secondDec.str_sign == '-')
	{
		return false;
	}
	else if ((NumOfDigits1 < NumOfDigits2) && (str_sign == '-') && (secondDec.str_sign == '-'))
	{
		return true;
	}
	else if ((NumOfDigits1 == NumOfDigits2) && (str_sign == '-') && (secondDec.str_sign == '-'))
	{
		return (str < secondDec.get_str());
	}
  return false;
}

bool BigDecimalInt::operator==(BigDecimalInt secondDec)
{
  if (str_sign != secondDec.str_sign)
  {
    return false;
  }
  else
  {
    return (str == secondDec.get_str());
  }
}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt secondDec)
{
  str_sign = secondDec.str_sign;
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
