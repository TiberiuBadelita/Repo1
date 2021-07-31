#include <iostream>
#include "Mazda.h"

using namespace std;

void Mazda::setCap()
{
	this->cap = 35;
}

void Mazda::setCons()
{
	this->cons = 7;
}

void Mazda::setSpeed()
{
	this->avg_speed = 110;

}

Mazda::Mazda()
{
	this->setCap();
	this->setCons();
	this->setSpeed();
}

int Mazda::getCap()
{
	return this->cap;
}

int Mazda::getCons()
{
	return this->cons;
}

int Mazda::getSpeed()
{
	return this->avg_speed;
}

void Mazda::Run(Weather w)
{
	if (w == 0)
	{
		this->getCons() = this->getCons() + (0.1 * this->getCons);

		this->getSpeed() = this->getSpeed() - (0.1 * this->getSpeed);
	 }
	else
		if(w == 1)
	   {
			this->getCons() = this->getCons() + (0.1 * this->getCons);

			this->getSpeed() = this->getSpeed() + (0.1 * this->getSpeed);
	    }
		else
			if(w == 2)
		 {
				this->getCons() = this->getCons() + (0.2 * this->getCons);

				this->getSpeed() = this->getSpeed() - (0.2 * this->getSpeed);
     		}
		 
}