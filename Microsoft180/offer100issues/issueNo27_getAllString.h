#ifndef __ISSUE_NO27__
#define __ISSUE_NO27__

#include <iostream>
using namespace std;

void printAllString(char *str, char* pBegin) {
    if (!str || !pBegin) return;
    if (*pBegin == '\0') {
        printf("%s\n", str);
    }
    for (char *p = pBegin; *p != '\0'; p++) {
        if (*p == *pBegin && p != pBegin) {
            continue;
        }
        char tmp = *pBegin;
        *pBegin = *p;
        *p = tmp;
        printAllString(str, pBegin + 1);
        *p = *pBegin;
        *pBegin = tmp;
    }
}

#endif // __ISSUE_NO27__
