#ifndef __ISSUE_NO38__
#define __ISSUE_NO38__

void printNum(char* number) {
    if (!number) return;
    size_t nLength = strlen(number);
    bool isBeginning0 = true;

    for (size_t i = 0; i < nLength; i++) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            printf("%c", number[i]);
        }
    }
    printf(" ");
}

bool increateNumber(char* number) {
    unsigned int nLength = strlen(number);
    int nSum = 0;
    int nPost = 1;
    bool isOverflowed = false;

    for (unsigned int i = nLength - 1; i >= 0; i--) {
        nSum = (number[i] - '0') + nPost;
        if (nSum < 10) {
            number[i] = '0' + nSum;
            nPost = 0;
            break;
        } else {
            nPost = 1;
            nSum -= 10;
            number[i] = '0' + nSum;
            if (i == 0) {
                isOverflowed = true;
            }
        }
    }
    return isOverflowed;
}

void printFrom1toN(int n) {
    char *number = new char[n+1];
    memset(number, '0', n+1);
    number[n] = '\0';
    while (!increateNumber(number)) {
        printNum(number);
    }
}

#endif // __ISSUE_NO38__
