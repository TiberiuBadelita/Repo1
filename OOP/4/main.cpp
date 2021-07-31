#include <iostream>
#include "Sort.h"

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Sort obj1(3, 32, 47);

	obj1.Print();

	int* arr{ new int[6]{ 5, 10, 7, 15, 3, 21 } };

	Sort obj2(arr);

	obj2.BubbleSort();

	obj2.Print();

	int *v =new int[]{ 1,2,3,5,4};

	Sort obj3(5,v);

	obj3.InsertSort();

	obj3.Print();

	obj3.GetElementsCount();

	Sort obj4(7, 5, 6, 7, 8, 9, 10, 11);

	obj4.Print();

	obj4.GetElementFromIndex(4);

	char s[1000] = "1,2,3,4,5";

	Sort obj5(s);

	obj5.Print();


	return 0;
}