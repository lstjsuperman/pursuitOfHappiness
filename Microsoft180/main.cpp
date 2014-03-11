#include <iostream>
#include "config/config.h"
#include "designParttern/AbstractFactory/abstractProduct.h"
#include "designParttern/AbstractFactory/abstractFactory.h"

using namespace std;

int main()
{
    cout << "This is jarek's Microsoft 180 issues resolution" << endl;
    #if __USE_ABSTRACT_FACTORY__
    AbstractFactory *factory = new ConcreateFactory1();
    AbstractProduct *productA = factory->getProductA();
    AbstractProductB *productB = factory->getProductB();
    productA->getInfo();
    productB->getBInfo();
    delete productB;
    delete productA;
    delete factory;
    #endif // __USE_ABSTRACT_FACTORY__
    return 0;
}
