#include <iostream>
#include "Weather.h"
#include "Circuit.h"

using namespace std;

 Circuit::Circuit()
{
	this->lenght = 0;
	this->nrc = 0;
}

void Circuit::SetLength(int value)
{
	this->lenght = value;
}

void Circuit::SetWeather(Weather w)
{
	this->w = w;
}

void Circuit::AddCar(Car* c)
{
	this->nrc++;

	Car** tmp;
	tmp = new Car * [this->nrc];

	for (int i = 0;i < this->nrc;i++)
		tmp[i] = this->v[i];
	delete[] this->v;

	this->v = tmp;

	this->v[this->nrc - 1] = c;

	this->v[this->nrc - 1].Run(this->w);
	
}


void Circuit::Race()
{
	for (int i = 0;i < this->nrc;i++)
		this->t[i] = 0;
	 
	for (int i = 0;i < this->nrc;i++)
		this->t[i] = this->lenght / this->v[i]->getSpeed();

}

void Circuit::ShowFinalRanks()
{
	for(int i=0;i<this->nrc-1; i++)
		for(int j=i+1; j<this->nrc;j++)
			if (this->t[i] > this->t[j])
			{
				Car* aux = new Car;
				
				aux = this->v[i];
				this->v[i] = this->v[j];
				this->v[j] = aux;

				int auxx;

				auxx = this->t[i];
				this->t[i] = this->t[j];
				this->t[j] = aux;
			}

	for (int i = 0;i < this->nrc;i++)
		if(this->t[i]!=0)
		cout <<this->v[i] << " " << this->t[i]<<endl;

	for(int i=0;i<this->nrc;i++)
		if(this->t[i]==0)
		cout << this->v[i] << " " << this->t[i] << endl;
	
}

void Circuit::ShowWhoDidNotFinis()
{
	for (int i = 0;i < this->nrc;i++)
		if (t[i] == 0)
			cout << this->v[i];
}

