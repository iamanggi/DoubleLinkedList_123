#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNO, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();						//step 1
	newNode->noMhs = nim;							//step 2
	newNode->name = nm;								//step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;

		}
		newNode->next = START;						//step 3
		if (START != NULL)
			START->prev = newNode;					//step 4
		newNode->prev = NULL;						//step 5
		START = newNode;							//step 6
		return;
	}
	/*inserting a Node Between Two Nodes in the list*/
	Node* current = START;							//step 1.a
	Node* previous = NULL;							//step 1.b
	while (current->next != NULL && current->next->noMhs < nim)			//step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;		//step 4
	newNode->prev = current;			//step 5
	if (current->next != NULL)
		current->next->prev = newNode;		//step 6
	current->next = newNode;				//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;				//step 1.a
	*current = START;				//step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {			//step 1.c
		*previous = *current;				//step 1.d
		*current = (*current)->next;		//step 1.e
	}
	return(*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;			//step 2
	if (previous != NULL)
		previous->next = current->next;			//step 3
	else
		START = current->next;

	delete current;			//	step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList empty" << endl;
	else {
		cout << "\nRecords in traverse order of roll number one: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in revtraverse order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
		
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	cout << "\n enter the roll number of student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "record not found" << endl;
	else
		cout << "record with roll number" << rollNo << "deleted" << endl;
}

void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nrecord not found" << endl;
	else {
		cout << "\nrecord found" << endl;
		cout << "\nroll number: " << curr->noMhs << endl;
		cout << "\nNama: " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nmenu" << endl;
			cout << "1. add a record to the list" << endl;
			cout << "2. delete a record form the list" << endl;
			cout << "3.view all records" << endl;
			cout << "4. view all records in the revtraverse order of roll numbers" << endl;
			cout << "5. search for a record  in the list" << endl;
			cout << "6. exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;
		}
	}
}