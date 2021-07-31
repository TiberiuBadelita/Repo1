#include "Weather.h"
#include "Car.h"

class Circuit {
	int lenght;
	int nrc;

	int t[100];
	
	Weather w;

	Car** v;
public :

	Circuit();
	void SetLength(int value);
	void SetWeather(Weather w);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();

};