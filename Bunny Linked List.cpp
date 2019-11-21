//Include statements for std libraries
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>

//Include statements for class header files
#include "Bunny.h"
#include "list.h"

using namespace std;
//Prototype Declarations
class list;

//Declaration of global variables.
int BunnyID = 0;
int turnCount = 0;

//Declaration and Definition of global functions
//Display functions: Generally to improve the text readability of the program
void typeDisplay(int type)
{
	if (type == 0)
	{
		cout << "This bunny is not of type radioactive_vampire" << endl;
	}

	if (type == 1)
	{
		cout << "This bunny is of type radioactive_vampire" << endl;
	}

}

void testStart()
{
	cout << "Hello world!" << endl;

	cout << "Starting Test\n" << endl;
	Bunny* bptr = new Bunny;
	cout << bptr->getAge() << endl;
	cout << bptr->getColor() << endl;
	cout << bptr->getSex() << endl;
	cout << bptr->getType() << endl;
	typeDisplay(bptr->getType());

	//delete bptr;
	//bptr = nullptr;

	List* listPtr = new List;

	//Test for copying bunny object unto the node of the linked list and obtaining the total amt of Bunnies in the list
	listPtr->createNode(bptr);

	delete bptr;
	bptr = nullptr;

	listPtr->getCount();
	listPtr->displayList();
	//End Test

	//Test for searching for a male bunny in list
	cout << listPtr->searchMale() << endl;

	//Test for increasing bunny object age
	Bunny* bptr2 = new Bunny;
	bptr2->increaseAge();
	cout << bptr2->getAge() << endl;

	delete bptr2;
	bptr2 = nullptr;
	//End Test

	//Test for reproduceBunny function
	listPtr->reproduceList();

	//End test

	//Test for looping initialization of bunny object and copying bunny object unto linked list
	for (int i = 0; i < 3; i++)
	{
		Bunny* bptr3 = new Bunny;
		listPtr->createNode(bptr3);

		delete bptr3;
		bptr3 = nullptr;
	}

	listPtr->displayList();
	//End Test

	//Test for node deletion
	listPtr->deleteNode(2);
	listPtr->displayList();
	//End Test

	//Test for deleting all nodes and the data inside the nodes
	listPtr->clearList();
	listPtr->displayList();

	//Test for culling bunnies
	for (int i = 0; i < 10; i++)
	{
		Bunny* bptr = new Bunny;
		listPtr->createNode(bptr);

		delete bptr;
		bptr = nullptr;
	}

	listPtr->cullBunny();
	listPtr->displayList();

	delete listPtr;
	listPtr = nullptr;

	//Redefinition of Global Variables
	BunnyID = 0;

	cout << "Successfully reached the end of all tests!\n" << endl;
	cout << "Press enter to start game!\n" << endl;

	//End of all tests.
	cin.get();
}

int main()
{
	srand(time_t(0));
	testStart();
	cout << "Game starts now!\n" << endl;
	//Object Initialization

	//Creates a list object off the heap
	List* listPtr = new List;

	//Bunny object creation off the heap
	for (int i = 0; i < 5; i++)
	{
		Bunny* bptr = new Bunny;
		listPtr->createNode(bptr);

		delete bptr;
		bptr = nullptr;
	}

	cout << "These are your starting bunnies!\n" << endl;
	listPtr->displayList();

	cout << "Press enter to continue!\n" << endl;
	cin.get();

	//Turn management
	while (1)
	{
		turnCount++;
		cout << "Turn " << turnCount << endl;
		cout << endl;

		//Increase age of all bunnies by 1
		listPtr->ageList();

		//If there is a male and female bunny age > 2, produce offspring
		if (listPtr->searchMale() == 1)
		{
			listPtr->reproduceList();
		}

		//Kill bunnies and delete nodes when their age is 10/50 (next two loops)
		//Non-vampire bunnies
		for (int i = 0; i < BunnyID; i++)
		{
			listPtr->searchDeath(1);
			if (listPtr->searchDeath(1) == 0)
			{
				break;
			}

			else if (listPtr->searchDeath(1) != 0)
			{
				listPtr->deleteNode(listPtr->searchDeath(1));
			}
		}

		//Vampire Bunnies
		for (int i = 0; i < BunnyID; i++)
		{
			listPtr->searchDeath(2);
			if (listPtr->searchDeath(2) == 0)
			{
				break;
			}

			else if (listPtr->searchDeath(2) != 0)
			{
				listPtr->deleteNode(listPtr->searchDeath(2));
			}
		}

		listPtr->displayList();
		cout << "The total amount of nodes in the list and alive Bunnies are " << listPtr->getCount() << endl;

		//Automatic Population Management
		if (listPtr->getCount() >= 1000)
		{
			cout << "Upper limit for bunny population has been reached, culling half the population randomly!" << endl;
			listPtr->cullBunny();
			listPtr->displayList();
			listPtr->getCount();
			cout << "The total amount of nodes in the list and alive Bunnies are " << listPtr->getCount() << endl;
		}

		if (listPtr->getCount() == 0)
		{
			cout << "No more bunnies are left alive, terminating program\n" << endl;
			return 0;
		}

		cin.get();
	}


	return 0;
}
