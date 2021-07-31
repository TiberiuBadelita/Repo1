#include <iostream>
#include "Ford.h"

using namespace std;

void Ford::setCap()
{
	this->cap = 40;
}

void Ford::setCons()
{
	this->cons = 9;
}

void Ford::setSpeed()
{
	this->avg_speed = 140;

}

Ford::Ford()
{
	this->setCap();
	this->setCons();
	this->setSpeed();
}

int Ford::getCap()
{
	return this->cap;
}

int Ford::getCons()
{
	return this->cons;
}

int Ford::getSpeed()
{
	return this->avg_speed;
}

void Ford::Run(Weather w)
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
