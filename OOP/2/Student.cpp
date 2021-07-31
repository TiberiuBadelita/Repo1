#include <iostream>
#include <cstring>
#include "Student.h"

void Student::Set_Name(char n[21]) {

	strcpy(this->name, n);
}

char  Student::Get_Name() {

	return this->name;
}

void  Student::Set_Grade_For_Math(int x) {

	this->gm = x;
}

int  Student::Get_Grade_For_Math() {

	return this->gm;
}

void  Student::Set_Grade_For_English(int x) {

	this->ge = x;
}

int  Student::Get_Grade_For_English() {

	return this->ge;
}

void  Student::Set_Grade_For_History(int x);
{
	this->gh = x;
}
int  Student::Get_Grade_For_History() {

	return this->gh;
}

int Student::Average_Grade() {

	return (this->gm + this->ge + this->gh) / 3;
}