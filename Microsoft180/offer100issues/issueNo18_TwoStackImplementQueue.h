#ifndef __ISSUE_NO18__
#define __ISSUE_NO18__

#include <stack>

namespace NO18 {
template <typename T>
class CQueue {
public:
    CQueue(){}
    ~CQueue(){}

    void appendTail(const T& node);
    void deleteHead();
private:
    stack<T> m_stack1;
    stack<T> m_stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node) {
    m_stack1.push(node);
}

template <typename T>
void CQueue<T>::deleteHead() {
    while(!m_stack1.empty()) {
        T tmp = m_stack1.top();
        m_stack2.push(tmp);
        m_stack1.pop();
    }
    if (!m_stack2.empty()) {
        m_stack2.pop();
    }
    while(!m_stack2.empty()) {
        m_stack1.push(m_stack2.top());
        m_stack2.pop();
    }
}

}

#endif // __ISSUE_NO18__
