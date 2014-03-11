#include "abstractFactory.h"

AbstractFactory::AbstractFactory() {
    cout << __FUNCTION__ << " constructed" << endl;
}

AbstractFactory::~AbstractFactory() {
    cout << __FUNCTION__ << " destructed" << endl;
}


ConcreateFactory1::ConcreateFactory1() {
    cout << __FUNCTION__ << " constructed" << endl;
}

ConcreateFactory1::~ConcreateFactory1() {
    cout << __FUNCTION__ << " destructed" << endl;
    for (vector<AbstractProduct*>::iterator it = productA_buffer.begin();
        it != productA_buffer.end(); it++) {
        if (*it) {
            delete *it;
            *it = NULL;
        }
    }
    productA_buffer.clear();
    for (vector<AbstractProductB*>::iterator itB = productB_buffer.begin();
        itB != productB_buffer.end(); itB++) {
        if (*itB) {
            delete *itB;
            *itB = NULL;
        }
    }
    productB_buffer.clear();
}

AbstractProduct *ConcreateFactory1::getProductA() {
    AbstractProduct* ret = new ConcreateProduct1();
    productA_buffer.push_back(ret);
    return ret;
}

AbstractProductB *ConcreateFactory1::getProductB() {
    AbstractProductB* ret = new ConcreateProductB1();
    productB_buffer.push_back(ret);
    return ret;
}

ConcreateFactory2::ConcreateFactory2() {
    cout << __FUNCTION__ << " constructed" << endl;
}

ConcreateFactory2::~ConcreateFactory2() {
    cout << __FUNCTION__ << " destructed" << endl;
    for (vector<AbstractProduct*>::iterator it = productA_buffer.begin();
        it != productA_buffer.end(); it++) {
        if (*it) {
            delete *it;
            *it = NULL;
        }
    }
    productA_buffer.clear();
    for (vector<AbstractProductB*>::iterator itB = productB_buffer.begin();
        itB != productB_buffer.end(); itB++) {
        if (*itB) {
            delete *itB;
            *itB = NULL;
        }
    }
    productB_buffer.clear();
}

AbstractProduct *ConcreateFactory2::getProductA() {
    AbstractProduct* ret = new ConcreateProduct2();
    productA_buffer.push_back(ret);
    return ret;
}

AbstractProductB *ConcreateFactory2::getProductB() {
    AbstractProductB* ret = new ConcreateProductB2();
    productB_buffer.push_back(ret);
    return ret;
}
