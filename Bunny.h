#ifndef BUNNY_H
#define BUNNY_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
//Bunny class to create bunny objects that display the characteristics of the obj: sex, name, age etc
class Bunny
{
protected:
	int age;
	int id;
	string sex;

private:
	string color;
	bool radioactive_mutant_vampire_bunny = NULL;

public:
	Bunny();
	Bunny(const Bunny& other);
	~Bunny();

	//Creates a child of the female bunny as long as it(parent) is not a mutant
	Bunny* reproduceBunny();

	//Declarations for get functions of bunny class
	int getAge();
	int getID();
	string getSex();
	string getColor();
	bool getType();

	//Declarations for set functions of bunny class
	void increaseAge();

};

#endif // BUNNY_H

