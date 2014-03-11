#ifndef __ISSUE_NO3__
#define __ISSUE_NO3__
#include <iostream>

using namespace std;

bool getMaxSub(int *pArray, int length, int& maxSubSum) {

    int curSum = 0;
    int maxSum = 0;
    int start = 0, end = 0, tmpStart = 0;

    for (int i = 0; i < length; i++) {
        curSum += pArray[i];
        if (curSum < 0) {
            curSum = 0;
            tmpStart = i + 1;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            end = i;
            start = tmpStart;
        }
    }

    maxSubSum = maxSum;
    cout << "Max sub start at " << start << " end at " << end << endl;
    cout << "Max sub is " << maxSum << endl;

}

#endif // __ISSUE_NO3__
