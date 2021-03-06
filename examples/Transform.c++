// -------------
// Transform.c++
// -------------

// http://en.cppreference.com/w/cpp/algorithm/transform

#include <algorithm>  // transform, equal
#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

using namespace std;

void test1 () {
    const int                 a[]  = {2, 3, 4};
    int                       b[5] = {};
    const function<int (int)> f = [] (int x) -> int {return x * x;};
    const int*                p    = transform(a, a + 3, b + 1, f);
    assert(p == b + 4);
    assert(equal(b, b + 5, begin({0, 4, 9, 16, 0})));}

void test2 () {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    const function<int (int)> f = [] (int x) -> int {return x * x;};
    vector<int>::iterator     p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Transform.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
