// lambda2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

int main()
{

    list<int> l;

    int n, x;

    cin >> n;

    for (int i = 0;i < n;i++) {
        cin >> x;
        l.push_back(x);
    }
    

    auto f = [&]() {
        list<int> aux;

        aux = l;

        int max = 0;

        while (aux.size() != 0)
        {

            if (max < aux.back())
                max = aux.back();

            aux.pop_back();
        }

        cout << "Maximul este:" << max;

    };

    f();
}
