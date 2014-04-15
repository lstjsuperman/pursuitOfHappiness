#ifndef __CHAP4_SEMANTICS_OF_FUNCTIONS__
#define __CHAP4_SEMANTICS_OF_FUNCTIONS__
#include <iostream>
#include <algorithm>
using namespace std;


class Point3D {
public:
    double x() {

        cout << 10.10 <<endl;
        return 10.10;
    }
private:
};

class HaveAStaticMember {
public:
    static int getMember() {
        cout << m_member << endl;
        return m_member;
    }
public:
    static void setMember(int member);
private:
    static int m_member;
};

int HaveAStaticMember::m_member = 10;
void HaveAStaticMember::setMember(int number) {
    cout << "m_member is set to " << number << endl;
    m_member = number;
}

void doSomething() {
    double (Point3D::*pmf)();
    double (Point3D::*coord)() = &Point3D::x;
    coord = &Point3D::x;
    Point3D origin;
    (origin.*coord)();
    Point3D *ptr = &origin;
    (ptr->*coord)();

    HaveAStaticMember tmp;
    tmp.setMember(10);
    tmp.getMember();

    int _array[] = {23, 12, 11, 5, 24, 18};
    int n = sizeof(_array) / sizeof(int);
    sort(_array, _array+n);
    cout <<"size is " << sizeof(_array) << endl;
    for (int i = 0; i < n; i++) {
        cout << "index:" << i << " " << _array[i] << endl;
    }

}

#endif // __CHAP4_SEMANTICS_OF_FUNCTIONS__
