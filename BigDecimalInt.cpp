#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr)
{
	// TODO: 000005656565 remove zeros until number bigger than 0 //done
	// TODO: + / - remove signs in the begin of string //done
	// TODO: use stoi
	// TODO: push the remaining into num vector
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
		sign = decStr[0];
		// Erasing the first character in the String
		// Where 0 is the first character index, 1 is the number of characters we need to remove from that index.
		decStr.erase(0, 1);
	}
	else if (!isdigit(decStr[0]))
	{
		cout << "Invalid String";
		return;
	}

	for (int i = 1; i < decStr.size(); ++i)
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
}
//...^_^...//