//#pragma once
//------------------------------------------
//              class queue
//------------------------------------------
// A dynamic singly Linked List to implement a queue
//------------------------------------------
#include "node.h"

class queue {
public:
	queue();
	//inserts phone customers
	void insertFront(int newEntry, float newTimeSpent, queue clientQueue);
	//inserts door customers
	void insertRear(int newEntry, float newTimeSpent); 
	//removes customers after their question has been answered
	bool deleteFront(); 
	//returns whether or not the current queue is empty
	bool isEmpty(); 
	//gets the time needed to answer the next customer's question
	float getNextPatient(); 
	//returns the length of the queue
	int getLength(); 
private:
	//points to the first element in the queue
	node *head; 
	//points to the last element in the queue
	node *rear; 
	//holds the length of the queue
	int length; 
};