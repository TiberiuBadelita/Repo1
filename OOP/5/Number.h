#include <iostream>

using namespace std;

class Number
{
	char* value;
	int vb10;
	int base;

public:

	Number();

	Number(int val);

	Number(const char* value, int base);

	~Number();

	Number(Number& o);
	
	Number(Number&& o);

	friend Number operator +(Number i , Number j);

	friend Number operator -(Number i, Number j);

	string operator !();

	char operator [](int index);

	Number& operator = (int val);

	Number& operator = (const char* val);

	Number& operator = (Number val);

	bool operator >(const Number& i);

	bool operator <(const Number& i);

	bool operator >=(const Number& i);

	bool operator <=(const Number& i);

	bool operator ==(const Number& i);

	bool operator !=(const Number& i);

	void operator +=(Number i);

	void operator --();

	void operator --(int val);

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); 

	int  GetBase();

};
