#include "list.h"

Node::Node()
{
	cout << "Node successfully constructed! (Default Constructor)" << endl;
}

Node::~Node()
{
	cout << "Node successfully destructed!" << endl;
}

List::List()
{
	cout << "List successfully constructed!(Default Constructor)" << endl;
	head = 0;
	tail = 0;
}

//Obtains the number of bunnies/nodes in the linked list
int List::getCount()
{
	int nodeCount = 0;
	Node* temp = head;

	while (temp != tail)
	{
		nodeCount++;
		temp = temp->next;
	}

	return nodeCount;
}

//Deletes half of the bunnies in the linked list randomly
void List::cullBunny()
{
	Node* temp = head;
	int nodeCount = getCount();
	int* arr = new int[nodeCount];
	int i = 0;

	while (temp != tail)
	{	
		arr[i] = temp->data->getID();
		temp = temp->next;
		i++;
	}

	int nCount = 0;
	int nodeSelector = 0;

	while (nCount != nodeCount / 2)
	{
		nodeSelector = rand() % nodeCount;
		deleteNode(arr[nodeSelector]);
		nCount++;
	}
	
	arr = nullptr;
	delete[] arr;

}

//Creates node at the start of the list using a pointer to Bunny object created off the heap, and copies it into the linked list.
void List::createNode(Bunny* addData)
{

	Node* new_node = new Node;
	new_node->data = new Bunny(*addData);
	new_node->next = 0;

	if (head == 0)
	{
		head = new_node;
		new_node->next = 0;
	}

	else if (head != 0)
	{
		new_node->next = head;
		head = new_node;
	}

	new_node = nullptr;
	delete new_node;
}


//Node deletion for head and every subsequent node according to Bunny's id
void List::deleteNode(int key)
{
	Node* temp = head,
	* prev = NULL;

	//If head node contains the key
	if (temp != tail && temp->data->getID() == key)
	{
		head = temp->next;
		delete temp->data;

		temp = nullptr;
		delete temp;

		return;
	}

	//For every subsequent node other than the head node
	while (temp != tail && temp->data->getID() != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == tail)
	{
		return;
	}

	prev->next = temp->next;
	delete temp->data;

	temp = nullptr;
	delete temp;
}

//Clears the list of all nodes
void List::clearList()
{
	Node* temp = head;

	while (temp != NULL)
	{
		Node* prev = temp;
		delete temp->data;
		temp = temp->next;
		delete prev;
	}

	head = NULL;
	tail = NULL;
}

//Searches for the presence of a male bunny age 2 and above in the linked list
bool List::searchMale()
{
	Node* temp = head;

	while (temp != tail)
	{
		if (temp->data->getSex() == "male" && temp->data->getAge() >= 2)
		{
			return 1;
		}

		temp = temp->next;
	}

	return 0;
}

//Searches the list for any bunny that is of dying age. Type 1 for normal, Type 2 for mutants
int List::searchDeath(int type)
{
	Node* temp = head;

	if (type == 1)
	{
		while (temp != tail && temp->data->getAge() != 10)
		{
			temp = temp->next;
		}

		if (temp == tail)
		{
			return 0;
		}

		return temp->data->getID();
	}

	if (type == 2)
	{
		while (temp != tail && temp->data->getAge() != 50)
		{
			temp = temp->next;
		}

		if (temp == tail)
		{
			return 0;
		}

		return temp->data->getID();
	}

	return 0;
}

//Increases all bunny age in the linked list by one.
void List::ageList()
{
	Node* temp = head;

	while (temp != tail)
	{
		temp->data->increaseAge();
		temp = temp->next;
	}
}

//Creates a child bunny for each female bunny in the list.
void List::reproduceList()
{
	Node* temp = head;

	while (temp != tail)
	{
		Bunny* bfptr = 0;

		bfptr = temp->data->reproduceBunny();
		if (bfptr != 0)
		{
			createNode(bfptr);
		}

		delete bfptr;
		bfptr = nullptr;

		temp = temp->next;
	}
}

//Displays all data in the list
void List::displayList()
{
	cout << "Displaying all nodes and corresponding bunnies in the linked list!" << endl;

	if (head == NULL)
	{
		cout << "List is empty!" << endl;
		return;
	}

	Node* current = head;
	while (current != tail)
	{
		cout << "Bunny's age is " << current->data->getAge() << endl;
		cout << "Bunny's color is " << current->data->getColor() << endl;
		cout << "Bunny's sex is " << current->data->getSex() << endl;
		cout << "Bunny's ID is " << current->data->getID() << endl;
		cout << endl;

		current = current->next;
	}

}


