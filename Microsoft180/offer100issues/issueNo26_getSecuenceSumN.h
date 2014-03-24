#ifndef __ISSUE_NO26__
#define __ISSUE_NO26__

#include <iostream>
using namespace std;

void printSequence(int start, int end) {
    cout << "Sequence:";
    for (int i = start; i <= end; i++) {
        cout << i << " ";
    }
    cout << endl;
}

void getSequenceSumN(int n) {
    if (n < 3) {
        cout << "Invalid input" << endl;
        return;
    }
    int startIndex = 1;
    int endIndex = 2;
    int middle = n/2;
    int sum = startIndex + endIndex;
    while(startIndex <= middle) {
        while (sum < n) {
            endIndex++;
            sum += endIndex;
        }
        if (sum == n) {
            printSequence(startIndex, endIndex);
        }
        startIndex++;
        endIndex = startIndex + 1;
        sum = startIndex + endIndex;
    }
}

#endif // __ISSUE_NO26__
