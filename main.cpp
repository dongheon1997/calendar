#include <iostream>

using namespace std;

class Calendar
{
private:
	int year;

public:
	Calendar(int i = 2019);
	void setYear(int i);
	void printDigitLine(int digit, int line) const;
	void printYear() const;
	bool isLeap() const;
	void printMonths() const;
	void print() const;
};

Calendar::Calendar(int i/*2019*/)
{
	year = i;
}

void Calendar::setYear(int i)
{
	year = i < 1 ? 1 : i;
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

void Calendar::printYear() const
{
	int arr[4];

	int temp = year;
	for (int i = 0; i < 4; i += 1)
	{
		arr[3 - i] = temp % 10;
		temp /= 10;
	}

	for (int i = 0; i < 5; i += 1)
	{
		for (int j = 0; j < 4; j += 1)
		{
			printDigitLine(arr[j], i);
			cout << "  ";
		}
		cout << endl;
	}
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

void Calendar::printMonths() const
{
	int cur[12] = { 0 };//이거 필수냐?
	int max[12] = { 31, isLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day[12];

}

void Calendar::print() const
{
	printYear();
	printMonths();
}

int main()
{
	Calendar c;
	c.print();

	return 0;
}