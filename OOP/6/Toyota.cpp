#include <iostream>
#include "Toyota.h"

using namespace std;

void Toyota::setCap()
{
	this->cap = 40;
}

void Toyota::setCons()
{
	this->cons = 7;
}

void Toyota::setSpeed()
{
	this->avg_speed = 120;

}

Toyota::Toyota()
{
	this->setCap();
	this->setCons();
	this->setSpeed();
}

int Toyota::getCap()
{
	return this->cap;
}

int Toyota::getCons()
{
	return this->cons;
}

int Toyota::getSpeed()
{
	return this->avg_speed;
}

void Toyota::Run(Weather w)
{
	if (w == 0)
	{
		this->getCons() = this->getCons() + (0.1 * this->getCons);

		this->getSpeed() = this->getSpeed() - (0.1 * this->getSpeed);
	}
	else
		if (w == 1)
		{
			this->getCons() = this->getCons() + (0.1 * this->getCons);

			this->getSpeed() = this->getSpeed() + (0.1 * this->getSpeed);
		}
		else
			if (w == 2)
			{
				this->getCons() = this->getCons() + (0.2 * this->getCons);

				this->getSpeed() = this->getSpeed() - (0.2 * this->getSpeed);
			}

}