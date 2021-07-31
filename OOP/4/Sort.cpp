#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include "Sort.h"

using namespace std;

#define _CRT_SECURE_NO_WARNINGS


Sort::Sort(int n, int minn, int maxx)
{
	this->nre = n;
	this->v = new int[n];

	for(int i=0;i<n;i++)
	this->v[i]=rand() % ((maxx - minn) + 1) + minn;
	
}

Sort::Sort(int* v)
{
	this->nre = v[0];
	this->v = new int[v[0]];

	for (int i = 0;i < v[0];i++)
		this->v[i] = v[i+1];

}

Sort::Sort(int n, int *v)
{
	this->nre = n;
	this->v = new int[n];

	for (int i = 0;i < n;i++)
		this->v[i] = v[i];

}

Sort::Sort(int count, ...)
{

	va_list arg;

	va_start(arg, count);

	this->nre = count;
	this->v = new int[count];

	for (int i = 0;i < count;i++) {
		int x = va_arg(arg, int);
		this->v[i] = x;
	}


}

Sort::Sort(char s[1000])
{

	int n = 0;

	char* p;

	char aux[1000];

	strcpy(aux, s);

	p = strtok(s, ",");

	while (p != NULL)
	{
		n++;
		p = strtok(NULL, ",");
	}

	this->nre = n;
	this->v = new int[n];

	n = 0;

	p = strtok(aux, ",");

	char auxx[100];
	int nrc = 0;

	while (p != NULL)
	{
		strcpy(auxx, p);
		nrc = 0;

		for (int i = 0;i < strlen(auxx);i++)
			nrc = nrc * 10 + (auxx[i] - '0');

		this->v[n] = nrc;
		n++;

		p = strtok(NULL, ",");
	}

}



void Sort::InsertSort(bool ascendent = false) {

	int i, key, j;
	for (i = 1; i < this->nre; i++)
	{
		key = this->v[i];
		j = i - 1;
		while (j >= 0 && this->v[j] > key)
		{
			this->v[j + 1] = this->v[j];
			j = j - 1;
		}
		this->v[j + 1] = key;
	}

}

void Sort::BubbleSort(bool ascendent = false) {

	int i, j;
	for (i = 0; i < this->nre - 1; i++)
		for (j = 0; j < this->nre - i - 1; j++)
			if (this->v[j] > this->v[j + 1])
			{
				int aux = this->v[j];
				this->v[j] = this->v[j + 1];
				this->v[j + 1] = aux;
			}

}


void Sort::Print()
{
	for (int i = 0; i <this->nre;i++)
		cout << this->v[i] << " ";

	    cout << endl;
}


int  Sort::GetElementsCount() {

	return this->nre;
}

int  GetElementFromIndex(int index) {

	return this->v[index];

}