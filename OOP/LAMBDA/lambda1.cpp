
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v;

    
        v.push_back("mama");
        v.push_back("Ionel merge la magazin");
        v.push_back("tata");
        v.push_back("Ionel joaca fotbal");
    

        auto f = [&]() {
          
            for (int i = 0;i < v.size()-1;i++)
               for(int j = i+1; j < v.size();j++) 
                   if (v.at(i).length() > v.at(j).length()) {
                       string aux;

                       aux = v.at(i);
                       v.at(i) = v.at(j);
                       v.at(j) = aux;
                   }
                   else
                       if(v.at(i).length() == v.at(j).length())
                           if(v.at(i).compare(v.at(j))>0){
                               string aux;

                               aux = v.at(i);
                               v.at(i) = v.at(j);
                               v.at(j) = aux;
                           }

                       
        };
     
        f();

        for (int i = 0;i < v.size();i++)
            cout << v.at(i) << endl;
    
    return 0;
}
