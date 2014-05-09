#ifndef __ISSUE_NO1__
#define __ISSUE_NO1__

typedef struct _Node {
    int element;
    struct Node *pLeft;
    struct Node *pRight;
} Node;

Node* parseNodeList(Node* pHead, bool asRight) {
    if (!pHead) return NULL;

    Node *left = NULL;
    if (pHead->pLeft) {
        left = parseNodeList(pHead->pLeft, false);
    }
    pHead->pLeft = left;
    if (left) {
        left->pRight = pHead;
    }
    Node *right = NULL;
    if (pHead->pRight) {
        right = parseNodeList(pHead->pRight, true);
    }
    pHead->pRight = right;
    if (right) {
       right->pLeft = pHead;
    }
    Node *pTmp = pHead;
    if (asRight) {
        while(pTmp->pLeft) {
            pTmp = pTmp->pLeft;
        }
    } else {
        while(pTmp->pRight) {
            pTmp = pTmp->pRight;
        }
    }
    return pTmp;
}


#endif // __ISSUE_NO1__
