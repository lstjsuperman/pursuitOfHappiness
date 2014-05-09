#ifndef __ISSUE_NO9__
#define __ISSUE_NO9__

namespace NO9 {
    typedef struct _Node {
        struct _Node* next;
        int value;
    } Node;
    char* getKFromTheEnd(Node* pHead, int K) {
        if (NULL == pHead) return NULL;
        Node* pAhead = pHead;
        Node* pBehind = NULL;
        for (int i = 0; i < K; i++) {
            if (pAhead->next != NULL) {
                pAhead = pHead->next;
            } else {
                return NULL;
            }
        }
        pBehind = pHead;
    }

    void testgetKFromTheEnd() {

    }
}
#endif // __ISSUE_NO9__
