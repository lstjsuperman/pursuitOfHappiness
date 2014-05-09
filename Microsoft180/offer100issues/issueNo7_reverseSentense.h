#ifndef __ISSUE_NO7__
#define __ISSUE_NO7__

void reverseChars(char* pBegin, char* pEnd) {
    if (!pBegin || !pEnd || pBegin == pEnd) return;
    while(pBegin < pEnd) {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        pBegin++;
        pEnd--;
    }
}

char *reverseSentenseNo7(char* input) {
    if (!input) return NULL;
    char* pStart = input;
    char* pEnd = input;
    while(*pEnd != '\0') ++pEnd;
    reverseChars(pStart, --pEnd);
    pStart = pEnd = input;
    while (*pStart != '\0') {
        if (*pStart == ' ') {
            pStart = ++pEnd;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            reverseChars(pStart, --pEnd);
            pStart = ++pEnd;
        } else {
            pEnd++;
        }
    }
    return input;
}

void testReverseSentence() {
    char *sentence = new char[100];
    memset(sentence, 0, 100);
    strncpy(sentence, "i really  love  you!", 100);
    printf("No.7 original is:%s\n", sentence);
    reverseSentenseNo7(sentence);
    printf("No.7 result is:%s\n", sentence);
}

#endif // __ISSUE_NO7__
