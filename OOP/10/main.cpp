#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    Array<int> v;

    for (int i = 0; i < 5; i++)
        v.Insert(i, i+10);

    cout << v[3];

    cout << v.Find(13);

    v.Print();
    
    return 0;
}
