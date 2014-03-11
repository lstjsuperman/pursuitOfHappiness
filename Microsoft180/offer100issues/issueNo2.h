#ifndef __ISSUE_NO2__
#define __ISSUE_NO2__

#include <deque>
#include <cassert>

using std::deque;

template <typename T>
class StackJ {
public:
    StackJ();
    virtual ~StackJ();

    T& top();
    const T& top() const;

    void push(const T& t);
    void pop();

    const T& min() const;

private:
    deque<T> m_data;
    deque<size_t> m_minIndex;
};

template<typename T>
StackJ<T>::StackJ(){}
template<typename T>
StackJ<T>::~StackJ(){}

template<typename T>
void StackJ<T>::push(const T& t) {
    m_data.push_back(t);
    if (m_minIndex.empty()) {
        m_minIndex.push_back(m_data.size() - 1);
    } else {
        if (t < m_data[m_minIndex.back()]) {
            m_minIndex.push_back(m_data.size() - 1);
        } else {
            m_minIndex.push_back(m_minIndex.back());
        }
    }
}

template<typename T>
void StackJ<T>::pop() {
    if (!m_data.empty()) {
        m_data.pop_back();
        m_minIndex.pop_back();
    }
}

template<typename T>
const T& StackJ<T>::min() const{
    assert(m_data.size() > 0);
    assert(m_minIndex.size() > 0);

    return m_data[m_minIndex.back()];
}

template<typename T>
T& StackJ<T>::top() {
    return m_data.back();
}

template<typename T>
const T& StackJ<T>::top() const {
    return m_data.back();
}

#endif
