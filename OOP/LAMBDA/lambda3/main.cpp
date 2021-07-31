#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
	MyVector v;

	v.Add(2);
	v.Add(10);
	v.Add(29);
	v.Add(2012);

	v.Delete(2);
   

	auto f = [&]() {
		
		for (int i = 0;i < v.size;i++)
			v[i] = v[i] * 2;
	};

	v.Iterate(f());
	

  
}

