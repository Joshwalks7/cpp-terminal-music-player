#ifndef TEST_H
#define TEST_H
using namespace std;

class Test {
    private:
        string name;
        string description;
        bool isComplete;

    public:
        Test(string uName, string uDescription);
        void printTaskStatus() const;
        void completeTask();
};

#endif // Test