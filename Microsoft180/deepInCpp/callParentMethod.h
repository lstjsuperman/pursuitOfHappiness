#ifndef __CALL_PARENT_METHOD__
#define __CALL_PARENT_METHOD__

#include <iostream>

using namespace std;

class Parent {
public:
    virtual void getName() {
        cout << "P:Jarek" << endl;
    }
    virtual void justPrint() {
        cout << "P:Print" << endl;
    }
    virtual ~Parent(){}
};

class Child: public Parent {
public:
    typedef Parent Super;
    virtual void getName() {
        cout << "C:Jarek" << endl;
    }
    virtual void justPrint() {
        Super::justPrint();
    }

};
#endif // __CALL_PARENT_METHOD__
