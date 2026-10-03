#include <iostream>
#include <vector>

#include "Test.h"

int main() {
    // Instantiate an object of the Test class
    Test myObject("Take out Trash", "Get the smelly stuff out of here!");

    // Call a member function
    myObject.printTaskStatus();
    myObject.completeTask();
    myObject.printTaskStatus();

    return 0;
}