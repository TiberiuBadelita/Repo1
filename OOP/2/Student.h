#include <iostream>

using namespace std;

class Student {

private:

	char name[21];
	int gm, ge, gh, ma;

public:

	void Set_Name(char n[21]);
	char Get_Name();
	void Set_Grade_For_Math(int x);
	int Get_Grade_For_Math();
	void Set_Grade_For_English(int x);
	int Get_Grade_For_English();
	void Set_Grade_For_History(int x);
	int Get_Grade_For_History();
	int Average_Grade();

};