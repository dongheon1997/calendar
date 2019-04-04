#include <iostream>
#include "Calendar.h"

using namespace std;

int main()
{
	Calendar c;

	int year, column;
	cout << "year: ";
	cin >> year;
	cout << "column(1 ~ 4): ";
	cin >> column;

	c.setYear(year);
	c.print(column);

	return 0;
}
