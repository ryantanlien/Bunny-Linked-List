#include "Bunny.h"

int extern BunnyID;

//Default Constructor
Bunny::Bunny()
{
	BunnyID++;
	id = BunnyID;
	age = 0;
	int nValue = rand() % 5;
	int nValue2 = rand() % 1001;
	int nValue3 = rand() % 3;
	switch (nValue) //Selector for color
	{
	case 1:
		color = "white";
		break;

	case 2:
		color = "brown";
		break;

	case 3:
		color = "black";
		break;

	case 4:
		color = "spotted";
		break;
	}

	if (nValue2 == 1) //Selector for radioactive_mutant_vampire_bunny
	{
		radioactive_mutant_vampire_bunny = true;
	}

	else
	{
		radioactive_mutant_vampire_bunny = false;
	}

	if (nValue3 == 1) //Selector for sex of the bunny upon creation
	{
		sex = "male";
	}

	else
	{
		sex = "female";
	}

	cout << "Bunny successfully constructed! (Default Constructor)" << endl;
}

//Copy constructor
Bunny::Bunny(const Bunny& other)
{
	this->age = other.age;
	this->id = other.id;
	this->color = other.color;
	this->sex = other.sex;
	cout << "Bunny successfully copied!" << endl;
}

Bunny::~Bunny()
{
	cout << "Bunny successfully destructed!" << endl;
}

Bunny* Bunny::reproduceBunny()
{
	Bunny* childptr = new Bunny;

	if (this->sex == "female" && this->radioactive_mutant_vampire_bunny == false && this->getAge() >= 2)
	{
		childptr->color = this->color;
	}

	else
	{
		childptr = 0;
		BunnyID--;
	}

	return childptr;
}

//Get functions for the characteristics of the bunny object
int Bunny::getAge()
{
	return age;
}

int Bunny::getID()
{
	return id;
}

string Bunny::getSex()
{
	return sex;
}

string Bunny::getColor()
{
	return color;
}

bool Bunny::getType()
{
	return radioactive_mutant_vampire_bunny;
}

//Set functions for the characteristics of the bunny object
void Bunny::increaseAge()
{
	age++;
}

