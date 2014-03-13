#ifndef __ISSUE_NO5__
#define __ISSUE_NO5__

void reverseJ(char* pBegin, char* pEnd) {
    if (pBegin == NULL || pEnd == NULL) {
        return;
    }
    char tmp;
    while(pBegin < pEnd) {
        tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        pBegin++;
        pEnd--;
    }
}

void reverseSentense(char* pSentense) {
    if (pSentense == NULL) {
        return;
    }
    char* pStart = pSentense;
    char* pEnd = pStart;
    while (*pEnd != '\0') {
        pEnd++;
    }
    --pEnd;
    reverseJ(pStart, pEnd);
    pStart = pEnd = pSentense;
    while (*pStart != '\0') {
        if (*pStart == ' ') {
            ++pStart;
            pEnd = pStart;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            reverseJ(pStart, --pEnd);
            pStart = ++pEnd;
        } else {
            ++pEnd;
        }
    }
}

#endif // __ISSUE_NO5__
