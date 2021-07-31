#include <iostream>
#include <cstring>
#include "Student.h"
#include "GlobalFunctions.h"

using namespace std;

int main()
{
    Student s1, s2;

    s1.Set_Name("Michael");
    s1.Set_Grade_For_English(9);
    s1.Set_Grade_For_History(7);
    s1.Set_Grade_For_Math(10);

    s2.Set_Name("John");
    s2.Set_Grade_For_English(10);
    s2.Set_Grade_For_History(10);
    s2.Set_Grade_For_Math(10);

    if (Cmp_AverageG(s1, s2)==1)
        cout << "Media lui" << s1.Get_Name() << "este mai mare decat a lui" << s2.Get_Name();
    else
        if(Cmp_AverageG(s1,s2)==-1)
            cout << "Media lui" << s2.Get_Name() << "este mai mare decat a lui" << s1.Get_Name();
        else
            cout<< cout << "Media lui" << s1.Get_Name() << "este egala cu media lui" << s2.Get_Name();
   
    //celelalte functii(Cmp_English,Cmp_Math etc.) sunt de asemenea functii pentru compararea notelor la engleza/mate/istorie sau compararea numelor a celor doi studenti s1,s2;
    
    return 0;
}

