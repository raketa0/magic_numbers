#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <set>

const std::string MAGIC = "Magic";
const std::string NON_MAGIC = "Non-magic";
const std::string ERROR = "Error";
const std::set<char> chDigits{ '1','2', '3', '4', '5', '6','7', '8', '9', '0' };
const std::string MAX_VALUE_UINT64_T = "18446744073709551615";
const int MAX_DIGIT_UINT64_T = 20;
const std::string ERROR_TOO_BIG = "The number is too big";
const std::string ERROR_INCORRECT_NUMBER = "Incorrectly entered number";
const std::string ENTER_NUMBER = "Enter a number!!!";
const std::string ERROR_START_NUMBER = "Error: The number cannot start with 0";
const std::string ERROR_START_NUMBER_NEGATIV = "The numbers are only positive";

std::string strNumber;

bool isÑorrectnessNumber(std::string strNumber)
{
	if (((strNumber[0] == '0') && strNumber.length() > 1) && strNumber[0] == '-')
	{
		std::cout << ERROR_START_NUMBER << std::endl;
		return false;
	}

	for (int i = 0; i < strNumber.length(); i++)
	{
		if (chDigits.count(strNumber[i]) == 0)
		{
			std::cout << ERROR_INCORRECT_NUMBER << std::endl;
			return false;
		}
	}

	if (strNumber.length() > MAX_DIGIT_UINT64_T)
	{
		std::cout << ERROR_TOO_BIG << std::endl;
		return false;
	}
	if (strNumber.length() == MAX_DIGIT_UINT64_T)
	{
		for (int i = 0; i < strNumber.length(); i++)
		{
			if (chDigits.count(strNumber[i]) == 0)
			{
				std::cout << ERROR_INCORRECT_NUMBER << std::endl;
				return false;
			}
			if ((strNumber[i] - '0') > (MAX_VALUE_UINT64_T[i] - '0'))
			{
				std::cout << ERROR_TOO_BIG << std::endl;
				return false;
			}
		}
	}

	return true;
}

std::string isMagicNumber(std::string strNumber)
{
	std::uint64_t Number;

	if (isÑorrectnessNumber(strNumber))
	{
		Number = std::stoull(strNumber);
	}
	else
	{
		return ERROR;
	}
	uint64_t Difference = Number;
	for (int i = 0; i < strNumber.length(); i++)
	{
		int sumDigit = strNumber[i] - '0';
		Difference = Difference - sumDigit;
	}

	if (Difference % 9 == 0)
	{
		return NON_MAGIC;
	}
	else
	{
		return MAGIC;
	}
}


int main()
{
	std::cout << ENTER_NUMBER << std::endl;
	std::cin >> strNumber;
	std::string result = isMagicNumber(strNumber);
	if (result == ERROR)
	{
		std::cout << result << std::endl;
		return 1;
	}

	std::cout << result << std::endl;
	return 0;
}
