#include "Weather.h"

class Car {

public:

	virtual void setCap() = 0;

	virtual void setCons() = 0;

	virtual void setSpeed() = 0;

	virtual int getCap() = 0;

	virtual int getCons() = 0;

	virtual int getSpeed() = 0;

	virtual void Run(Weather w) = 0;
};
