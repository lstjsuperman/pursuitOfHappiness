#ifndef __ISSUE_NO26__2__
#define __ISSUE_NO26__2__

namespace NO26 {
    void printSequence(int sum, int start, int end);
    void getContinuenousSequence(int n) {
        int start = 1;
        int end = 2;
        int middle = (n+1)/2;
        int sum = start + end;
        while(start < middle) {
            if (sum == n) {
                printSequence(n, start, end);
            }
            while (sum > n) {
                sum -= start;
                start++;
                if (sum == n) {
                    printSequence(n, start, end);
                }
            }
            end++;
            sum += end;
        }
    }
    void printSequence(int sum, int start, int end) {
        std::cout << sum << " Sequence is:";
        for (int i = start; i <= end; i++) {
            std::cout << " " << i;
        }
        std::cout << endl;
    }

    void testGetSequence() {
        int n1 = 15, n2 = 18, n3 = 19;
        getContinuenousSequence(n1);
        getContinuenousSequence(n2);
        getContinuenousSequence(n3);
    }
}

#endif // __ISSUE_NO26__2__
