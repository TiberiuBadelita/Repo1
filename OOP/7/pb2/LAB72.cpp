#include <iostream>
#include "Vector.h"

using namespace std;

bool compare(int a, int b)
{
	if (b < a)
		return true;
	else
		return false;
}
bool equal(int x, int y)
{
	if (x == y)
		return true;
	else
		return false;
}

int main()
{
	MyVector <int> a;
	a.push(10);
	a.push(20);
	a.push(1);
	a.push(203);
	a.push(16);
	a.push(23);
	a.print();
	cout << a.pop() << endl;
	a.print();
	a.remove(4);
	a.print();
	a.insert(30, 3);
	a.print();
	a.sort(nullptr);
	a.print();
	cout << a.get(3) << endl;
	a.set(30, 2);
	a.print();
	cout << a.count() << endl;
	cout << a.firstIndexOf(30, equal);
	return 0;
}
