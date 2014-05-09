#ifndef __ISSUE_NO13__
#define __ISSUE_NO13__

namespace NO13 {
    char FirstNotRepeatingChar(const char *pString) {
        if (!pString) {
            return 0;
        }
        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for (int i = 0; i < tableSize; i++) {
            hashTable[i] = 0;
        }

        const char *pHashKey = pString;
        while(*pHashKey != '\0') {
            hashTable[(unsigned)*(pHashKey++)] ++;
        }

        pHashKey = pString;
        while(*pHashKey != '\0') {
            if (hashTable[(unsigned)*pHashKey] == 1) {
                return *pHashKey;
            }
            pHashKey++;
        }
        return 0;
    }

    void testFirstNotRepeatingChar() {
        const char *testChars = "cefcfedeaa";
        char ret = FirstNotRepeatingChar(testChars);
        std:: cout << "Result is :" << ret << endl;
    }
}

#endif // __ISSUE_NO13__
