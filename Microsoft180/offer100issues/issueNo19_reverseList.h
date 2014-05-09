#ifndef __ISSUE_NO19__
#define __ISSUE_NO19__

#include <string.h>

namespace NO19 {

struct ListNode {
    int element;
    ListNode* pNext;
    ListNode() {
        element = 0;
        pNext = NULL;
    }
};

ListNode* reverseList(ListNode* pNode) {
    if (!pNode) {
        return NULL;
    }
    ListNode* pCurrent = pNode;
    stack<ListNode*> nodeStack;
    while(pCurrent != NULL) {
        nodeStack.push(pCurrent);
        pCurrent = pCurrent->pNext;
    }
    ListNode* ret = nodeStack.top();
    ListNode* tmpNode = ret;
    while(!nodeStack.empty()) {
        tmpNode->pNext = nodeStack.top();
        nodeStack.pop();
        tmpNode = tmpNode->pNext;
    }
    tmpNode->pNext = NULL;
    return ret;
}

ListNode* reverseList2(ListNode* pNode) {
    if (!pNode) return NULL;
    ListNode *prev = NULL;
    ListNode *pCurrent = pNode;
    ListNode *pReverseHead = NULL;
    while (pCurrent) {
        ListNode *pNext = pCurrent->pNext;
        if (!pNext) {
            pReverseHead = pCurrent;
        }
        pCurrent->pNext = prev;
        prev = pCurrent;
        pCurrent = pNext;
    }
    return pReverseHead;
}


void printListNode(ListNode* pNode) {
    if (!pNode) return;
    while(pNode) {
        std::cout << pNode->element << endl;
        pNode = pNode->pNext;
    }
}

void testReverseListNode() {
    ListNode Node1;
    Node1.element = 10;
    ListNode Node2;
    Node2.element = 12;
    Node2.pNext = &Node1;
    ListNode Node3;
    Node3.element = 14;
    Node3.pNext = &Node2;
    printListNode(&Node3);
    ListNode*pTmp = reverseList(&Node3);
    printListNode(pTmp);
    pTmp = reverseList2(pTmp);
    printListNode(pTmp);
}


}

#endif // __ISSUE_NO19__
