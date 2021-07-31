#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

string lower(string s)
{

    for (int i = 0;i < s.length();i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
      

            if (s[0] == ' ')
                s.erase(0, 1);
     
    return s;
}

int main()
{ 

    ifstream f("date.txt");

    string s;

    map <string, int> m;

    getline(f, s);
    
    string aux;
    int nr = 0;

    for (int i = 0;i < s.length();i++)
        if ( (s.at(i) == ' ' || s.at(i) == ',' || s.at(i) == '.' || s.at(i) == '!' || s.at(i) == '?') && ( s.at(i-1) != ' ' && s.at(i - 1) != '.'))
        {
            aux = s.substr(i - nr, nr);
            nr = 0;
                m.insert(pair<string, int>(lower(aux), 0));
        }
        else
            nr++;

    for (int i = 0;i < s.length();i++)
        if ((s.at(i) == ' ' || s.at(i) == ',' || s.at(i) == '.' || s.at(i) == '!' || s.at(i) == '?') && (s.at(i - 1) != ' ' && s.at(i - 1) != '.' ))
        {
            aux = s.substr(i - nr, nr);
            nr = 0;
            m.find(lower(aux))->second++;
        }
        else
            nr++;
   

    priority_queue<int>q1;
    priority_queue<string, vector<string>, greater<string>>q2;

    for (auto i = m.begin(); i != m.end(); i++)
        q1.push(i->second);



    while (!q1.empty()) {

        for (auto i = m.begin(); i != m.end(); i++)
            if (i->second == q1.top())
                q2.push(i->first);
          

        while(!q2.empty())
        {
            cout << q2.top() << " => " << q1.top() << endl << endl;
            q1.pop();
            q2.pop();

        }

    }
   
    cout << "-----------------";

    return 0;
}


