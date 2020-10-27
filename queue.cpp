#include <iostream>
#include "queue.h"

//----------------------------------------------------
//	                       constructor
//----------------------------------------------------
queue::queue()
{
	head = NULL;
	rear = NULL;
	length = 0;
} // constructor

  //----------------------------------------------------
  //				       insertFront
  //----------------------------------------------------
  // Given: the new customer number,
  //        the time needed for their question,
  //        and the queue being added to
  //----------------------------------------------------
void queue::insertFront(int newEntry, float newTimeSpent, queue clientQueue) {
	node * newNode = new node(newEntry, newTimeSpent);
	length += 1;
	if(clientQueue.isEmpty()){
		//this->
		head = newNode;
		//this->
		rear = newNode;
	}
	else{
		newNode->next = head->next;//this->
		
		//this->
		head->next = newNode;
	}
	
	delete newNode;
	return;
} // insertFront()


  //----------------------------------------------------
  //				       insertRear
  //----------------------------------------------------
  // Given: the new customer number,
  //        the time needed for their question,
  //----------------------------------------------------
void queue::insertRear(int newEntry, float newTimeSpent) {
	node * newNode = new node(newEntry, newTimeSpent);

	if(rear == NULL){
		head = newNode;
		rear = newNode;
	}
	else{
		rear->next = newNode;
		rear = newNode;
		rear->next = NULL;
	}
	length += 1;
	delete newNode;
	return;
} // insertRear()

  //----------------------------------------------------
  //				       isEmpty
  //----------------------------------------------------
  // Returns: a boolean indicating whether or not the
  // 		  queue is empty
  //----------------------------------------------------
bool queue::isEmpty(){
	return(head == NULL);
} // isEmpty()

  //----------------------------------------------------
  //				   deleteFront
  //----------------------------------------------------
  // Returns: a boolean indicating whether or not the 
  //          front element was successfullly deleted
  //----------------------------------------------------
bool queue::deleteFront() {
	if (head == NULL)
		return false;
	else {
		length -= 1;
		node *deleteNode = new node;
		deleteNode = head;
		head = deleteNode->next;
		
		delete deleteNode->next;
		delete deleteNode;
		return true;
	}
	
} // deleteFront()

  //----------------------------------------------------
  //				   getNextPatient
  //----------------------------------------------------
  // Returns: the time needed to answer the question
  //          of the first person in the queue
  //----------------------------------------------------
float queue::getNextPatient(){
	if (head == NULL)
		return 0;
	else
	  return head->timeSpent;
  } // getNextPatient()
  
    //----------------------------------------------------
  //				   getLength
  //----------------------------------------------------
  // Returns: an int indicating the length of the queue
  //----------------------------------------------------
int queue::getLength(){
	  return length;
  } // getLength()
  