#include "Car.h"

class Toyota :public Car {

	int cap;
	int cons;
	int avg_speed;

public:

	Toyota();

	void setCap();

	void setCons();

	void setSpeed();

	int getCap();

	int getCons();

	int getSpeed();

	void Run(Weather w);
};