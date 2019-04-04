class Calendar
{
private:
	int year;

	void printDigitLine(int digit, int line) const;
	bool isLeap() const;
public:
	Calendar(int i = 2019);
	void setYear(int i);
	void printYear(int column = 3) const;
	void printMonths(int column = 3) const;
	void print(int column = 3) const;
};
