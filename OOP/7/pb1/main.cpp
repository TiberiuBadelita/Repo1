#include <iostream>

using namespace std;

float operator""_Kelvin(const char* x)
{

    int nr=0;

    while ((*x) != 0)
    {
        nr = nr * 10 + (*x) - '0';

        x++;
    }

    return nr-273.15;
}

float operator""_Fahrenheit(const char* x)
{

    int nr = 0;

    while ((*x) != 0)
    {
        nr = nr * 10 + (*x) - '0';

        x++;
    }

    return (nr-32)/1.8;
}

int main() {

    float a = 300_Kelvin;

    float b = 120_Fahrenheit;

    cout << a <<" -> grade Celsius din Kelvin"<<endl;
    
    cout << b <<" -> grade Celsius din Fahrenheit";

    return 0;

}
