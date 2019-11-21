#ifndef LIST_H
#define LIST_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Bunny.h"

using namespace std;

//Linked list definition
struct Node
{
	Bunny* data;
	struct Node* next;

public:
	Node();
	~Node();
};

class List
{
protected:
	Node* head;
	Node* tail;

private:


public:
	List();

	//Node manipulation
	void createNode(Bunny* addData);
	void deleteNode(int key);
	void clearList();

	//List manipulation
	int getCount();
	int searchDeath(int type);
	bool searchMale();

	void ageList();
	void displayList();
	void reproduceList();
	void cullBunny();


};

#endif // LIST_H
