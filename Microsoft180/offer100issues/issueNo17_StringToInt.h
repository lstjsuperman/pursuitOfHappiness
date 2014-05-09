#ifndef __ISSUE_NO17__
#define __ISSUE_NO17__
#include <limits>
namespace NO17 {
    typedef enum {
        PR_GOOD = 0,
        PR_BAD
    } PARSE_RESULT;
    PARSE_RESULT parse_result = PR_BAD;
    int parseStringToInt(const char* pString) {
        if (!pString) return 0;
        const char* pCurrent = pString;
        bool isMinus = false;
        if (*pCurrent == '+') {
            isMinus = false;
            pCurrent++;
        } else if(*pCurrent == '-'){
            isMinus = true;
            pCurrent++;
        }
        int ret = 0;
        while (*pCurrent != '\0') {
            if ('0' <= *pCurrent && *pCurrent <= '9') {
                ret = ret*10 + (*pCurrent - '0');
                if (ret > std::numeric_limits<int>::max()) {
                    ret = 0;
                    break;
                }
            } else {
                std::cout << "Parse Error! Not a valid Int representation" << std::endl;
                ret = 0;
                break;
            }
            pCurrent++;
        }
        if (*pCurrent == '\0') {
            parse_result = PR_GOOD;
            if (isMinus) {
                ret = 0 - ret;
            }
        }
        return ret;
    }

    void testParseStringToInt() {
        const char *pString = "a-8475";
        int ret = parseStringToInt(pString);
        std::cout << "Parse result is :" << ret << std::endl;
    }
}
#endif // __ISSUE_NO17__
