#include <iostream>
#include "Mercedes.h"

using namespace std;

void Mercedes::setCap()
{
	this->cap = 50;
}

void Mercedes::setCons()
{
	this->cons = 11;
}

void Mercedes::setSpeed()
{
	this->avg_speed = 160;

}

Mercedes::Mercedes()
{
	this->setCap();
	this->setCons();
	this->setSpeed();
}

int Mercedes::getCap()
{
	return this->cap;
}

int Mercedes::getCons()
{
	return this->cons;
}

int Mercedes::getSpeed()
{
	return this->avg_speed;
}

void Mercedes::Run(Weather w)
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