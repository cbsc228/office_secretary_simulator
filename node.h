//#pragma once
//------------------------------------------
//              class node
//------------------------------------------
// Describes a node in a unique-customerNumber Linked List
//------------------------------------------
#include <string>
using namespace std;

class node {
	friend class queue;
public:
	//default constructor
	node(); 
	//overloaded constructor
	node(int newEntry, float timeSpent); 
private:
	// customerNumber to the node
	int customerNumber;		
	//the time given to the cutomer by the secretary so far
	float timeSpent;		
	// pointer to next node in list
	node * next;			
};