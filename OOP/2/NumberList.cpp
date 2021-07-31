#include <iostream>

#include "NumberList.h"

using namespace std;

void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{

    this->count++;
    if (this->count >= 10)
        return false;
    else {
        this->numbers[count] = x;
        return true;
    }

}

void NumberList::Sort() {

    int aux;

    for(int i=1;i<=this->count-1;i++)
        for (int j = i + 1;j <= this->count;j++)
            if(this->numbers[i]>this->numbers[j])
        {
            aux = this->numbers[i];
            this->numbers[i] = this->numbers[j];
            this->numbers[j] = aux;

        }

}

void NumberList::Print() {

    for (int i = 1;i <= this->count;i++)
        cout << this->numbers[i]<< " ";

    cout << endl;

}
