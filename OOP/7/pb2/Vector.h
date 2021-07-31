#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T = int>
class MyVector
{
public:
	T* v;
	int nr_elemente, max;
	MyVector()
	{
		nr_elemente = 0;
		max = 100;
		v = (T*)malloc(max * sizeof(T));
	}
	void push(T x)	
	{
		if (nr_elemente + 1 > max)
		{
			max = max * 2;
			(T*)realloc(v, max * sizeof(T));
		}
		v[nr_elemente] = x;
		nr_elemente++;
	}
	T pop()
	{
		T x = v[nr_elemente - 1];
		nr_elemente--;
		return x;
	}
	void remove(int index)	
	{
		for (int i = index - 1; i < nr_elemente; i++)
			v[i] = v[i + 1];
		nr_elemente--;
	}
	void insert(T x, int index)	
	{
		if (nr_elemente + 1 > max)
		{
			max = max * 2;
			(T*)realloc(v, max * sizeof(T));
		}
		for (int i = nr_elemente; i > index - 1; i--)
			v[i] = v[i - 1];
		v[index - 1] = x;
		nr_elemente++;
	}
	void sort(bool (*compare)(T, T))		
	{										
		int i, j;
		T temp;
		for (i = 0; i < nr_elemente - 1; i++)
			for (j = i + 1; j < nr_elemente; j++)
				if (compare == nullptr)
				{
					if (v[j] < v[i])
					{
						temp = v[j];
						v[j] = v[i];
						v[i] = temp;
					}
				}
				else
					if (compare(v[i], v[j]) == true)
					{
						temp = v[j];
						v[j] = v[i];
						v[i] = temp;
					}
	}
	const T& get(int index)		
	{
		return v[index - 1];
	}
	void set(T x, int index)	
	{
		v[index - 1] = x;
	}
	int count()				
	{
		return nr_elemente;
	}
	int firstIndexOf(T x, bool (*equal)(T, T))	
	{												
													
		for (int i = 0; i < nr_elemente; i++)
			if (equal == nullptr)
			{
				if (x == v[i])
					return i + 1;
			}
			else
				if (equal(x, v[i]) == true)
					return i + 1;
		return 0;
	}
	void print()
	{
		for (int i = 0; i < nr_elemente; i++)
			cout << v[i] << " ";
		cout << endl;
	}

};