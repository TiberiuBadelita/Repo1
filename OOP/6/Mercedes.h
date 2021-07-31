#include "Car.h"

class Mercedes :public Car {

	int cap;
	int cons;
	int avg_speed;

public:

	Mercedes();

	void setCap();

	void setCons();

	void setSpeed();

	int getCap();

	int getCons();

	int getSpeed();

	void Run(Weather w);
};