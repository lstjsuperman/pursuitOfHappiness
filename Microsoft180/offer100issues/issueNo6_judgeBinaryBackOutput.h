#ifndef __ISSUE_NO6__
#define __ISSUE_NO6__

bool isBinarySearchTree(vector<int> &input, unsigned start, unsigned end) {
    if (start == end) return true;
    unsigned leftStart = start, leftEnd, rightStart, rightEnd = end - 1;
    for (unsigned i = start; i < end; i++) {
        if (input[i] > input[end]) {
            leftEnd = i -1;
            rightStart = i;
            break;
        }
    }
    for (unsigned i = rightStart; i < end; i++) {
        if (input[i] < input[end]) {
            return false;
        }
    }
    return isBinarySearchTree(input, leftStart, leftEnd) && isBinarySearchTree(input, rightStart, rightEnd);
}

void testIsBinary() {
    int oArray[] = {5, 7, 6, 9, 11, 10, 8};
    vector<int> v_test(oArray, oArray + sizeof(oArray)/ sizeof(int));
    bool ret = isBinarySearchTree(v_test, 0, sizeof(oArray)/sizeof(int) - 1);
    string result = ret ? "is" : "not";
    cout << "Vector " << result << " binary" << endl;
}

#endif // __ISSUE_NO6__
