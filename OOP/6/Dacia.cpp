#include <iostream>
#include "Dacia.h"

using namespace std;

void Dacia::setCap()
{
	this->cap = 30;
}

void Dacia::setCons()
{
	this->cons = 6;
}

void Dacia::setSpeed()
{
	this->avg_speed = 90;

}

Dacia::Dacia()
{
	this->setCap();
	this->setCons();
	this->setSpeed();
}

int Dacia::getCap()
{
	return this->cap;
}

int Dacia::getCons()
{
	return this->cons;
}

int Dacia::getSpeed()
{
	return this->avg_speed;
}

void Dacia::Run(Weather w)
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