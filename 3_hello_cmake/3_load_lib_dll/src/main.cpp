#include <iostream>
#include "head.h"

int main() {
    using namespace std;
    int a = 10, b = 8;
    cout << "a=" << a << "; b=" << b << endl;
    cout << "a+b=" << add(a, b) << endl;
    cout << "a-b=" << sub(a, b) << endl;
    cout << "a*b=" << mul(a, b)<< endl;
    cout << "a/b=" << my_div(a, b) << endl;
    return 0;
}