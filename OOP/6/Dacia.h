#include "Car.h"

class Dacia :public Car {

	int cap;
	int cons;
	int avg_speed;

public:

	Dacia();

	void setCap();

	void setCons();

	void setSpeed();

	int getCap();

	int getCons();

	int getSpeed();

	void Run(Weather w);
};