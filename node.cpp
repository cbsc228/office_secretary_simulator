#include <iostream>
#include <iomanip>
#include "node.h"

//------------------------------------------
//         constructors
//------------------------------------------
node::node() {
	customerNumber = 0;
	timeSpent = 0;
	next = NULL;
} // constructor (default)

node::node(int newEntry, float newTimeSpent) {
	customerNumber = newEntry;
	timeSpent = newTimeSpent;
	next = NULL;
} // overloaded constructor