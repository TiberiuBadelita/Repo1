#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Number.h"

using namespace std;

Number::Number(int val): vb10(val),base(10) {

	this->value = new char[1000];

	itoa(val, value, 10);

	strcpy(this->value, value);
}

Number::Number(const char* value, int base)
{
	this->value = new char[1000];
	strcpy(this->value, value);

	int nr10 = 0, p = 1;

	for (int i = strlen(this->value) - 1;i >= 0;i--) {
		if (base<=10)
			nr10 = nr10 + (this->value[i] - '0') * p;
		else
			nr10 = nr10 + (this->value[i] - 'A' + 10) * p;

			p = p * base;
	}

	this->vb10 = nr10;

	this->base = base;

}

Number::Number(Number& o)
{
	this->value = new char[1000];

	strcpy(this->value, o.value);

	this->base = o.base;

	this->vb10 = o.vb10;
}

Number::Number(Number&& o)
{
	this->value = new char[1000];

	strcpy(this->value, o.value);

	this->base = o.base;

	this->vb10 = o.vb10;
}


Number::~Number()
{
	delete this->value;
}

Number operator +(Number i, Number j)
{
	char* value = new char[1000];

	if (i.base > j.base)
		j.base = i.base;
	else
		i.base = j.base;

	itoa(i.vb10+j.vb10, value, i.base);

	i.vb10 = i.vb10 + j.vb10;
	strcpy(i.value, value);

	return i;
}

Number operator -(Number i, Number j)
{
	char* value = new char[1000];

	if (i.base > j.base)
		j.base = i.base;
	else
		i.base = j.base;

	itoa(i.vb10 - j.vb10, value, i.base);

	i.vb10 = i.vb10 - j.vb10;
	strcpy(i.value, value);

	return i;
}

char Number::operator [](int index)
{
	return this->value[index];
}

Number& Number::operator = (int val)
{
	if (this->value != nullptr) {
		itoa(val, this->value, this->base);
		this->vb10 = val;
	}
	else
	{
		this->value = new char[1000];

		itoa(val, this->value, 10);

		this->vb10 = val;

		this->base = 10;
	}

	return (*this);
}

Number& Number::operator = (const char* val)
{
	if (this->value != nullptr) {
		strcpy(this->value, val);
		this->vb10 = atoi(val);
	}
	else
	{
		this->value = new char[1000];

		strcpy(this->value, val);

		this->vb10 = atoi(val);

		this->base = 10;
	}

	return (*this);

}

Number& Number::operator = (Number val) {

	if (this->value != nullptr) {
		strcpy(this->value, val.value);
		this->vb10 = val.vb10;
		this->base = val.base;
		
	}
	else
	{
		this->value = new char[1000];
		strcpy(this->value, val.value);
		this->vb10 = val.vb10;
		this->base = val.base;

	}

	return (*this);

}

bool Number::operator >(const Number& i) {

	if (this->vb10 > i.vb10)
		return true;
	else
		return false;
}

bool Number::operator <(const Number& i) {

	if (this->vb10 < i.vb10)
		return true;
	else
		return false;
}

bool Number::operator <=(const Number& i) {

	if (this->vb10 <= i.vb10)
		return true;
	else
		return false;
}

bool Number::operator >=(const Number& i) {

	if (this->vb10 >= i.vb10)
		return true;
	else
		return false;
}

bool Number::operator ==(const Number& i) {

	if (this->vb10 == i.vb10)
		return true;
	else
		return false;
}

bool Number::operator !=(const Number& i) {

	if (this->vb10 != i.vb10)
		return true;
	else
		return false;
}

void Number::operator +=(Number i) {

	char* value = new char[1000];

	if (this->base > i.base)
		i.base = this->base;
	else
		this->base = i.base;

	itoa(i.vb10 + this->vb10, value, i.base);

	this->vb10 = i.vb10 + this->vb10;
	strcpy(this->value, value);

}

void Number::operator --()
{
	strcpy(this->value, this->value + 1);

	int nr10 = 0, p = 1;

	for (int i = strlen(this->value) - 1;i >= 0;i--) {
		nr10 = nr10 + (this->value[i] - '0') * p;
		p = p * this->base;
	}

	this->vb10 = nr10;

}

void Number::operator --(int val)
{
	strcpy(this->value + strlen(this->value) - 1, this->value + strlen(this->value));

	int nr10 = 0, p = 1;

	for (int i = strlen(this->value) - 1;i >= 0;i--) {
		nr10 = nr10 + (this->value[i] - '0') * p;
		p = p * this->base;
	}

	this->vb10 = nr10;
}


void Number::SwitchBase(int newBase)
{
	itoa(this->vb10, this->value, newBase);

	this->base = newBase;

}


void Number::Print()
{
	cout << this->value<<endl;

}


int  Number::GetDigitsCount()
{
	return strlen(this->value);
}


int Number::GetBase()
{
	return this->base;
}