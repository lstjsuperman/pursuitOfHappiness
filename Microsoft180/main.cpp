#include <iostream>
#include <cstdio>
#include <cstring>
#include "config/config.h"
#include "designParttern/AbstractFactory/abstractProduct.h"
#include "designParttern/AbstractFactory/abstractFactory.h"
#if __USE_OFFER_2_
#include "offer100issues/issueNo2.h"
#include "offer100issues/issueNo3.h"
#include "offer100issues/issueNo4_smallestK.h"
#include "offer100issues/issueNo5_reverseSentense.h"
#include "offer100issues/issueNo26_getSecuenceSumN.h"
#include "offer100issues/issueNo27_getAllString.h"
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

    #if 0 //Issue No.4
    vector<int> in_arr;
    in_arr.push_back(46);
    in_arr.push_back(38);
    in_arr.push_back(26);
    in_arr.push_back(73);
    in_arr.push_back(17);
    in_arr.push_back(12);
    in_arr.push_back(34);

    IntMaxHeap result_heap;
    getSmallestK(in_arr, result_heap, 5);
    for (IntMaxHeap::reverse_iterator it = result_heap.rbegin();
        it != result_heap.rend();
        it++) {
        cout << *it << endl;
    }
    #endif // 1

    #if 0 //Issue No.5
    char* pSentense = new char(100);
    memset(pSentense, 100, 0);
    strncpy(pSentense, "I am a student", strlen("I am a student."));
    reverseSentense(pSentense);
    cout << pSentense << endl;
    delete[] pSentense;
    #endif // 1

    #if 0 //Issue No.26
    getSequenceSumN(15);
    #endif // 1

    #if 1 // Issue No.27
    char* str = new char[10];
    memset(str, 0, 10);
    strncpy(str, "aac", 10);
    printAllString(str, str );
    delete[] str;
    #endif // 1

    return 0;
}
