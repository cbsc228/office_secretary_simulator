//Assignment 1
//Name: Craig Scarboro
//Class: CS315-001
//Description: Simlulates a secretary taking clients at 
//             his counter and at the phone as they come 
//             in as determined by a random number generator. 
//Assistence: No outside assistence was used.


#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include "queue.h"

//an arbitrarily large number used to ensure deletion
//is not performed on an empty queue
const float LARGE_NUMBER = 1000000.0;

//returns a random value between 0 and maxValue
float randomNumber(int maxValue){
	float randomValue = (maxValue * (((float) rand())/RAND_MAX));
	return randomValue;
}

//tests to see if the user input is in a valid range
bool positiveValueTest(int numToTest){
	if (numToTest <= 0)
		return true;
	else
		return false;
}
//tells the user if their input is not valid
//and asks the user for a new value given the constraints
void userInputCheck(float &userInput){
	cout << "Please enter a non-zero positive value." << endl;
		  cout << "->";
		  cin >> userInput;
		  cin.ignore(256,'\n');
}

//gets the user input and converts it to float
float getUserInput(){
	  string userInput;
	  cout << "->";
	  cin >> userInput;
	  float input = stof(userInput,NULL);
	  
	  //cin.ignore(256,'\n');
	  return input;
}

//returns what action should be performed next based
//on which falls next in the timeline
int minValue(float valOne, float valTwo, float valThree){
	float small;
	int minIndicator;
	
	if (valOne < valTwo){
		small = valOne;
		minIndicator = 1;
	}
	else {
		small = valTwo;
		minIndicator = 2;
	}
	
	if (small < valThree)
		return minIndicator;
	else {
		minIndicator = 3;
		return minIndicator;
	}
		
}

int main(){
	  
	  //initializes the necessary variables
	  //queue for clients
	  queue clientQueue; 
	  //used for randomization and incremention the simulated time
	  float questionAnswerTime, doorCustomerTime, phoneCustomerTime; 
	  //user input as for the maximums of the randomized variables
	  float qUser, dUser, pUser; 
	  float currentTime = 0;
	  int customerNumber = 0; 
	  //the maximum run time of the program given by the user
	  float runTime = 0; 
	  //used to determine whether the program should add a phone/door
	  //customer or answer an existing question
	  int nextAction; 
	  
	  //the following variables are used to determine which event is 
	  //supposed to happen next in the timeline of the simulator
	  float doorTimeAdvance = 0;
	  float phoneTimeAdvance = 0;
	  float questionTimeAdvance = 0;
	  
	  //seeds the random number generator based on the time of day
	  srand(time(NULL));
	  
	  //welcome statement
	  cout << "Welcome to my secretary simulator!" << endl;
	  
	  
	  
	  
	  //determines the range of values for q
	  cout << "What do you want the maximum time for the secretary to answer a question to be?" << endl;
	  qUser = getUserInput();
	  
	  //ensures the user given value falls within an acceptable range
	  while(positiveValueTest(qUser))
		  userInputCheck(qUser);
	  
	  
	  
	  
	  
	  //determines the range of values for d
	  cout << "What do you want the maximum time for someone to come through the front door to be?" << endl;
	  dUser = getUserInput();
	  
	  //ensures the user given value falls within an acceptable range
	  while(positiveValueTest(dUser))
		  userInputCheck(dUser);
	  
	  
	  
	  
	  
	  //determines the range of values for p
	  cout << "What do you want the maximum time for someone to call on the phone to be?" << endl;
	  pUser = getUserInput();
	  
	  //ensures the user given value falls within an acceptable range
	  while(positiveValueTest(pUser))
		  userInputCheck(pUser);
	  
	  
	  
	  //gets the length of simulated time the simulation will run for
	  cout << "How many simulated seconds do you want the program to run for?" << endl;
	  runTime = getUserInput();
	  
	  //ensures the user given value falls within an acceptable range
	  while(positiveValueTest(runTime))
		  userInputCheck(runTime);
	  

	  //determines when the first phone and door customers will come in
	  doorCustomerTime = randomNumber(dUser);
	  phoneCustomerTime = randomNumber(pUser);
	  //adds sequential customers and handels when questions are answered.
	  while(currentTime <= runTime){
		  
		  doorTimeAdvance = doorCustomerTime + currentTime;
		  phoneTimeAdvance = phoneCustomerTime + currentTime;
		  questionTimeAdvance = clientQueue.getNextPatient() + currentTime;
		  
		  //ensures the program does not attempt to answer the question of a client when the queue is empty
		  if(clientQueue.isEmpty()){
				nextAction = minValue(doorTimeAdvance, phoneTimeAdvance, LARGE_NUMBER);
			  }
		  else{
				nextAction = minValue(doorTimeAdvance, phoneTimeAdvance, questionTimeAdvance);
			  }
		  
		  
		  
		  switch (nextAction){
			  
			  //handles the situation in which a door client is to be added to the queue
			  case 1:
				  currentTime += doorCustomerTime;
				  
				  questionAnswerTime = randomNumber(qUser);
				  customerNumber += 1;
				  clientQueue.insertRear(customerNumber, questionAnswerTime);
				  cout << "A door customer has just been added to the line." << endl;
				  cout << "This is customer number " << customerNumber << endl;
				  cout << "The currentTime is " << currentTime << endl;
				  if (clientQueue.getLength() == 1)
					  cout << "The line currently has " << clientQueue.getLength() << " person in it" << endl;
				  else
					cout << "The line currently has " << clientQueue.getLength() << " people in it" << endl;
				  
				  cout << endl << endl;
				  
				  //determines when the next door customer will come in
				  doorCustomerTime = randomNumber(dUser);	  
				  break;
				  
				  //handles the situation in which a phone client is to be added to the queue
			  case 2:
				  currentTime += phoneCustomerTime;
				  
				  questionAnswerTime = randomNumber(qUser);
				  customerNumber += 1;
				  clientQueue.insertFront(customerNumber, questionAnswerTime, clientQueue);
				  
				  cout << "A customer has just called in and has been put to the front of the line." << endl;
				  cout << "This is customer number " << customerNumber << endl;
				  cout << "The currentTime is " << currentTime << endl;
				  if (clientQueue.getLength() == 1)
					  cout << "The line currently has " << clientQueue.getLength() << " person in it" << endl;
				  else
					cout << "The line currently has " << clientQueue.getLength() << " people in it" << endl;
				  
				  cout << endl << endl;
				  
				  //determines when the next phone customer will come in
				  phoneCustomerTime = randomNumber(pUser);
			      break;
				  
				  //handles the situation in which a client's question is to be answered
			  case 3:
			  //safety case to make sure deletion is not carried on an empty queue
				  if(clientQueue.deleteFront()){
					currentTime += clientQueue.getNextPatient();
					cout << "The customer at the front of the line just had their question answered." << endl;
					cout << "This is customer number " << customerNumber << endl;
					cout << "The currentTime is " << currentTime << endl;
					if (clientQueue.getLength() == 1)
					  cout << "The line currently has " << clientQueue.getLength() << " person in it" << endl;
					else
					  cout << "The line currently has " << clientQueue.getLength() << " people in it" << endl;
					
					cout << endl << endl;
				  }
				  else {
					  cout << "ERROR: The program attempted to delete a customer from the beginning of an empty queue." << endl;
					}
				  break;
		  }
	  }
	  
	  return 0;
  }