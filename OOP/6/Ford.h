#include "Car.h"

class Ford :public Car {

	int cap;
	int cons;
	int avg_speed;

public:

	 Ford();
	 
	 void setCap();

	 void setCons();

	 void setSpeed();

	 int getCap();

	 int getCons();

	 int getSpeed();

	 void Run(Weather w);
};