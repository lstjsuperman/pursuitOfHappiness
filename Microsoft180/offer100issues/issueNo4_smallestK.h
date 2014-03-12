#ifndef __ISSUE_NO4__
#define __ISSUE_NO4__

#include <set>
#include <iostream>

using std::cout;
using std::endl;

typedef multiset<int, greater<int> > IntMaxHeap;
void getSmallestK(const vector<int>& a, IntMaxHeap& ret, unsigned k) {
    if (a.size() < 0 || k == 0) {
        return;
    }
    for (vector<int>::const_iterator it = a.begin(); it != a.end(); it++) {
        if (ret.size() < k) {
            ret.insert(*it);
        } else {
            IntMaxHeap::iterator beginIterator = ret.begin();
            if (*it < *beginIterator) {
                ret.erase(beginIterator);
                ret.insert(*it);
            }
        }
    }
}

#endif // __ISSUE_NO4__
