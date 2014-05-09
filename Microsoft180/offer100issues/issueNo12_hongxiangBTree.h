#ifndef __ISSUE_NO12__
#define __ISSUE_NO12__

namespace No12 {

    struct BTreeNode {
        int element;
        BTreeNode *left;
        BTreeNode *right;
    };

    void printBTreeLeftToRight(BTreeNode *root) {
        if (!root) {
            return;
        }
        std::deque<BTreeNode* > tmpQueue;
        tmpQueue.push_back(root);

        while(!tmpQueue.empty()) {
            BTreeNode* head = tmpQueue.front();
            tmpQueue.pop_front();
            std::cout << head->element << std::endl;

            if (head->left) {
                tmpQueue.push_back(head->left);
            }
            if (head->right) {
                tmpQueue.push_back(head->right);
            }
        }
    }

}

#endif // __ISSUE_NO12__
