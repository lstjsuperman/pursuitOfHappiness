#ifndef __ABSTRACT_FACTORY__
#define __ABSTRACT_FACTORY__

#include <vector>
#include "abstractProduct.h"

using std::vector;

class AbstractFactory {
public:
    AbstractFactory ();
    virtual ~AbstractFactory ();
    virtual AbstractProduct *getProductA() = 0;
    virtual AbstractProductB *getProductB() = 0;
};

class ConcreateFactory1: public AbstractFactory {
public:
    ConcreateFactory1();
    ~ConcreateFactory1();
    AbstractProduct *getProductA();
    AbstractProductB *getProductB();
private:
    vector<AbstractProduct*> productA_buffer;
    vector<AbstractProductB*> productB_buffer;
};

class ConcreateFactory2: public AbstractFactory {
public:
    ConcreateFactory2();
    ~ConcreateFactory2();
    AbstractProduct *getProductA();
    AbstractProductB *getProductB();
private:
    vector<AbstractProduct*> productA_buffer;
    vector<AbstractProductB*> productB_buffer;
};
#endif // __ABSTRACT_FACTORY__
