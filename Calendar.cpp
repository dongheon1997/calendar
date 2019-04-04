#include <iostream>
#include "Calendar.h"

using namespace std;

Calendar::Calendar(int i/*2019*/)
{
	year = i;
}

void Calendar::setYear(int i)
{
	year = i;
}

void Calendar::printDigitLine(int digit, int line) const
{
	switch (line)
	{
	case 0:
		switch (digit)
		{
		case 0:
		case 2:
		case 3:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			cout << "#####";
			break;
		case 1:
			cout << "  #  ";
			break;
		case 4:
			cout << "#   #";
			break;
		}
		break;
	case 1:
		switch (digit)
		{
		case 0:
		case 4:
		case 8:
		case 9:
			cout << "#   #";
			break;
		case 1:
			cout << "  #  ";
			break;
		case 2:
		case 3:
		case 7:
			cout << "    #";
			break;
		case 5:
		case 6:
			cout << "#    ";
			break;
		}
		break;
	case 2:
		switch (digit)
		{
		case 0:
			cout << "#   #";
			break;
		case 1:
			cout << "  #  ";
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
			cout << "#####";
			break;
		case 7:
			cout << "    #";
			break;
		}
		break;
	case 3:
		switch (digit)
		{
		case 0:
		case 6:
		case 8:
			cout << "#   #";
			break;
		case 1:
			cout << "  #  ";
			break;
		case 2:
			cout << "#    ";
			break;
		case 3:
		case 4:
		case 5:
		case 7:
		case 9:
			cout << "    #";
			break;
		}
		break;
	case 4:
		switch (digit)
		{
		case 0:
		case 2:
		case 3:
		case 5:
		case 6:
		case 8:
		case 9:
			cout << "#####";
			break;
		case 1:
			cout << "  #  ";
			break;
		case 4:
		case 7:
			cout << "    #";
			break;
		}
		break;
	}
}

void Calendar::printYear(int column/*3*/) const
{
	if (column > 4) column = 4;
	else if (column < 1) column = 1;

	int arr[4];

	int temp = year;
	for (int i = 0; i < 4; i += 1)
	{
		arr[3 - i] = temp % 10;
		temp /= 10;
	}

	for (int i = 0; i < 5; i += 1)
	{
		for (int j = 0; j < column - 1; j += 1)
		{
			cout << "               ";
		}

		for (int j = 0; j < 4; j += 1)
		{
			printDigitLine(arr[j], i);
			cout << "  ";
		}
		cout << endl;
	}

	cout << endl;
}

bool Calendar::isLeap() const
{
	if (year % 4)
	{
		return false;
	}
	else if (year % 100)
	{
		return true;
	}
	else if (year % 400)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Calendar::printMonths(int column/*3*/) const
{
	if (column > 4) column = 4;
	else if (column < 1) column = 1;

	int nowDate[12] = {};
	int maxDate[12] = { 31, isLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nowDay[12];

	int temp = year - 1;
	nowDay[0] = (temp * 365 + temp / 4 - temp / 100 + temp / 400 + 1) % 7;
	for (int i = 0; i < 11; i += 1)
	{
		nowDay[i + 1] = (nowDay[i] + maxDate[i]) % 7;
	}

	for (int i = 0; i < 12; i += column)
	{
		for (int j = 0; j < column; j += 1)
		{
			printf("%2d월                          ", i + j + 1);
		}

		cout << endl;

		for (int j = 0; j < column; j += 1)
		{
			cout << "일  월  화  수  목  금  토    ";
		}

		cout << endl;
		
		int finish = 0;
		while (finish < column)
		{
			for (int j = 0; j < column; j += 1)
			{
				for (int k = 0; k < 7; k += 1)
				{
					if (nowDay[i + j] == k && nowDate[i + j] < maxDate[i + j])
					{
						printf("%2d  ", ++nowDate[i + j]);
						++nowDay[i + j] %= 7;

						if (nowDate[i + j] == maxDate[i + j]) finish += 1;
					}
					else
					{
						cout << "    ";
					}
				}
				cout << "  ";
			}
			cout << endl;
		}

		cout << endl;
	}
}

void Calendar::print(int column/*3*/) const
{
	if (column > 4) column = 4;
	else if (column < 1) column = 1;

	printYear(column);
	printMonths(column);
}
