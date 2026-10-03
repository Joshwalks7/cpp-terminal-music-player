#include <iostream>
#include "Test.h"
using namespace std;

Test::Test(string uName, string uDescription) {
    name = uName;
    description = uDescription;
    isComplete = false;
}

void Test::printTaskStatus() const {
    cout << "Task: " << name << "-- Description: " << description << " Completion: " << (isComplete ? "done" : "Not done");
}
void Test::completeTask() {
    isComplete = true;
}