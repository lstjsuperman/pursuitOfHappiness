#ifndef __ABSTRACT_PRODUCT__
#define __ABSTRACT_PRODUCT__
#include <iostream>
using std::cout;
using std::endl;

class AbstractProduct {
public:
    AbstractProduct(){}
    ~AbstractProduct(){}
    virtual void getInfo() {
        cout << __FUNCTION__ << " A" << endl;
    }
private:
};

class ConcreateProduct1: public AbstractProduct {
public:
    void getInfo() {
        cout << __FUNCTION__ << " A1" << endl;
    }
};

class ConcreateProduct2: public AbstractProduct {
public:
    void getInfo() {
        cout << __FUNCTION__  << " A2" <<endl;
    }
};

class AbstractProductB {
public:
    virtual void getBInfo() {
        cout << __FUNCTION__ << " B" << endl;
    }
};

class ConcreateProductB1: public AbstractProductB {
public:
    void getBInfo() {
        cout << __FUNCTION__ << " B1" << endl;
    }
};


class ConcreateProductB2: public AbstractProductB {
public:
    void getBInfo() {
        cout << __FUNCTION__ << " B2" << endl;
    }
};
#endif // __ABSTRACT_PRODUCT__
