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
#include "offer100issues/issueNo38_printNbitNumber.h"
#include "insideCppObjectModel/chap4_semantics_of_functions.h"
#include "offer100issues/issueNo100_Dynamic_Programming.h"
#include "deepInCpp/callParentMethod.h"
#include "offer100issues/issueNo5_getTheKSmallest.h"
#include "offer100issues/issueNo6_judgeBinaryBackOutput.h"
#include "offer100issues/issueNo7_reverseSentense.h"
#include "offer100issues/issueNo13_firstOnlyOne.h"
#include "offer100issues/issueNo17_StringToInt.h"
#include "offer100issues/issueNo18_TwoStackImplementQueue.h"
#include "offer100issues/issueNo19_reverseList.h"
#include "offer100issues/issueNo20_LongestCommonSub.h"
#include "offer100issues/issueNo25_calculate1times.h"
#include "offer100issues/issueNo26_FindContinuousSequence.h"
#endif // __USE_OFFER_2_

#define __USE__ISSUE__26

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

#if 0 // No.2
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
            it++)
    {
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

#if 0 // Issue No.27
    char* str = new char[10];
    memset(str, 0, 10);
    strncpy(str, "aac", 10);
    printAllString(str, str );
    delete[] str;
#endif // 1

#if 0 //Issue No.38
    printFrom1toN(3);
#endif // 1

#if 0 // Call parent method

Parent *ptr = new Child();
ptr->getName();
ptr->justPrint();

#endif // 1

#if 0 // No.5
    testGetKSmallest(3);
#endif // 1

#if 0 // No.6
    testIsBinary();
#endif // 1

#if 0 // No.7
    testReverseSentence();
#endif // 1

#if 0
    doSomething();
    getMaxValue();
#endif //

#if 0 //Issue No.13

NO13::testFirstNotRepeatingChar();

#endif // 1

#if 0 //Issue No.17
    NO17::testParseStringToInt();
#endif // 1
#if 0 //Issue No.19
    NO19::testReverseListNode();
#endif //

#ifdef __USE__ISSUE__20
    NO20::testLCS();
#endif
#ifdef __USE__ISSUE__25
    NO25::testNumberOfOne();
#endif
#ifdef __USE__ISSUE__26
    NO26::testGetSequence();
#endif
    return 0;
}
