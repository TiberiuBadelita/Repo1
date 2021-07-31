#include <iostream>
#include <cstring>

#include "GlobalFunctions.h"
#include "Student.h"

using namespace std;

int Cmp_Name(Student s1, Student s2){

	if (strcmp(s1.Get_Name(), s2.Get_Name()) > 0)
		return 1;
	else
		if (strcmp(s1.Get_Name(), s2.Get_Name()) < 0)
			return -1;
		else
			return 0;
}

int Cmp_Math(Student s1, Student s2) {

	if (s1.Get_Grade_For_Math() > s2.Get_Grade_For_Math())
		return 1;
	else
		if (s1.Get_Grade_For_Math() < s2.Get_Grade_For_Math())
			return -1;
		else
			return 0;

}

int Cmp_History(Student s1, Student s2) {

	if (s1.Get_Grade_For_History() > s2.Get_Grade_For_History())
		return 1;
	else
		if (s1.Get_Grade_For_History() < s2.Get_Grade_For_History())
			return -1;
		else
			return 0;

}

int Cmp_English(Student s1, Student s2) {

	if (s1.Get_Grade_For_English() > s2.Get_Grade_For_English())
		return 1;
	else
		if (s1.Get_Grade_For_English() < s2.Get_Grade_For_English())
			return -1;
		else
			return 0;
}

int Cmp_AverageG(Student s1, Student s2) {

	if (s1.Average_Grade() > s2.Average_Grade())
		return 1;
	else
		if (s1.Average_Grade() < s2.Average_Grade())
			return -1;
		else
			return 0;
}