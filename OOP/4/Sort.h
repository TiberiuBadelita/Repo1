#include<iostream>
#include<vector>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Sort
{
    int nre;
    int *v;
   

public:

    Sort(int n, int minn, int maxx);

    Sort(int* v);

    Sort(int n, int* v);

    Sort(int count, ...);

    Sort(char s[1000]);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};