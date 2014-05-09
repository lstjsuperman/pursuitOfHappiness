#ifndef __ISSUENO5_SMALL_K__
#define __ISSUENO5_SMALL_K__

#include <queue>
using std::priority_queue;

template <typename Type>
void getKSmallestValues(vector<Type> &input_array, unsigned K) {
    priority_queue<Type, vector<Type>, less<Type> > tmp_queue;
    for (unsigned i = 0; i < input_array.size(); i++) {
        if (tmp_queue.size() < K)
            tmp_queue.push(input_array[i]);
        else {
            Type cur_max = tmp_queue.top();
            if (cur_max > input_array[i]) {
                tmp_queue.pop();
                tmp_queue.push(input_array[i]);
            }
        }
    }

    cout << K << " smallest values are " ;
    while(!tmp_queue.empty()) {
        cout << tmp_queue.top() << " ";
        tmp_queue.pop();
    }
    cout << endl;
}

void getKLargestValues(const vector<int> &input, unsigned K) {
    multiset<int, less<int> > results;
    multiset<int, less<int> >::iterator it;
    results.clear();
    for (unsigned i = 0; i < input.size(); i++) {
        if (results.size() < K) {
            results.insert(input[i]);
        } else {
            it = results.begin();
            if (*results.begin() < input[i]) {
                results.erase(it);
                results.insert(input[i]);
            }
        }
    }
    cout << K << " largest values are ";
    it = results.begin();
    for (; it!= results.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void testGetKSmallest(int k) {
    int array[] = {12,14,34,23, 22,17,13,15,20,9};
    vector<int> test_vector(array, array+(sizeof(array)/sizeof(int)));
    getKSmallestValues<int>(test_vector, k);
    getKLargestValues(test_vector, k);

}


#endif // __ISSUENO5_SMALL_K__
