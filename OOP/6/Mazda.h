#include "Car.h"

class Mazda:public Car {

	int cap;
	int cons;
	int avg_speed;

public:

	Mazda();

	void setCap();

	void setCons();

	void setSpeed();

	int getCap();

	int getCons();

	int getSpeed();

	void Run(Weather w);
};