#include <iostream>
#include "config/config.h"
#include "designParttern/AbstractFactory/abstractProduct.h"
#include "designParttern/AbstractFactory/abstractFactory.h"
#if __USE_OFFER_2_
#include "offer100issues/issueNo2.h"
#include "offer100issues/issueNo3.h"
#endif // __USE_OFFER_2_

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

    #if __USE_OFFER_2_
    StackJ<int> mystack;
    mystack.push(16);
    mystack.push(13);
    mystack.push(14);
    mystack.push(5);
    cout << "Min:" << mystack.min() << endl;
    mystack.pop();
    cout << "Min:" << mystack.min() << endl;
    mystack.pop();
    cout << "Min:" << mystack.min() << endl;
    mystack.pop();
    cout << "Min:" << mystack.min() << endl;
    #endif // __USE_OFFER_2_

    int a[7] = {-4, 5, -6, 2, -4, 6, -3};
    int maxSub = 0;
    getMaxSub(a, 7, maxSub);
    return 0;
}
