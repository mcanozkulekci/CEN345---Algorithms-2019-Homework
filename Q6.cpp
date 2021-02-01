#include <iostream>
#include <fstream>
using namespace std;


class Node {
public:
	int c, base, exp;

	Node* next;
	Node* prev;
};

class LinkedList {
public:
	LinkedList();	//done
	~LinkedList();
	void Push(int c, int base, int exp);	//done
	void Purge(Node*walk);
	void Display();	//done
	void ReadFile();
	void Merge();
	int MergeOperations(Node*walk, Node*current, int* sum);
private:
	Node* first, * last;
	int LIST_LEN = 0;
};

LinkedList::LinkedList() {
	first = NULL, last = NULL;
}

LinkedList::~LinkedList() {
	while (first->next != NULL) {
		first = first->next;
		delete first->prev;
	}
	delete first;
}

//adding to queue structure
void LinkedList::Push(int c, int base, int exp) {
	Node* temp = new Node();
	temp->c = c;
	temp->base = base;
	temp->exp = exp;
	temp->next = NULL;

	if (first == NULL) {
		first = temp;
		temp->prev = NULL;
		last = temp;
	}
	else {
		last->next = temp;
		temp->prev = last;
		last = temp;
	}

	LIST_LEN++;
}

//simple node deletion
void LinkedList::Purge(Node* node) {
	if (node == first) {
		first = first->next;
		delete first->prev;
		first->prev = NULL;
	}
	else if (node == last) {
		last = last->prev;
		delete last->next;
		last->next = NULL;
	}
	else {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		delete node;
	}
}

//merge the coefficients with the same exponent and bases
void LinkedList::Merge() {
	Node* current = first;
	Node* finnishline = last;	//read until a specified finishline so new added nodes wont be read.
	Node* next;
	Node* walk;
	int base, exp;
	static int sum = 0;

	while (current != finnishline) {
		base = current->base, exp = current->exp;

		walk = first;
		next = current->next;

		sum = 0;	//reset sum of coefficients for every new base&exponent

		MergeOperations(walk, current, &sum);
		Push(sum, base, exp); //add new node

		current = next;
	}
}

//get the sum of the coefficients with same exponent and bases
int LinkedList::MergeOperations(Node* walk, Node* current, int* sum) {
	if (current == NULL)
		return 0;
	if (walk == NULL)
		return 0;
	if (current->base == walk->base && current->exp == walk->exp)
		* sum += walk->c;
	MergeOperations(walk->next, current, sum);
	if (current->base == walk->base && current->exp == walk->exp)
		Purge(walk);
	return *sum;
}

//simply pretty display 
void LinkedList::Display() {
	Node* walk = first;

	while (walk != NULL) {
		cout << walk->c << "x" << walk->base << "^" << walk->exp << " --> ";
		walk = walk->next;
	}
	cout << "\n" << endl;
}

//Read the file
void LinkedList::ReadFile() {
	ifstream file("TEXT.txt");
	int c, base, exp;
	
	//read the variables in a line with given order,
	//when no variables left(end of the file) it will stop the loop
	while (file >> c >> base >> exp) {
		Push(c, base, exp);
	}
}

int main() {
	int c, base, exp;
	int option;
	LinkedList list;

	list.ReadFile();
	list.Display();

	while (1) {
		cout << "\n1-Merge & Display\n2-Read file\n0-Exit\n" << endl;
		cin >> option;

		switch (option) {
		case 1:
			list.Merge();
			list.Display();
			break;
		
			//tried to create an empty new list while
			//program is running, still need to work on it
		case 2: {
			LinkedList list;
			list.ReadFile();
			list.Display();
			break;
			}

		case 0:
			return 0;
		}
	}
}