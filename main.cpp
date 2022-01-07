#include <iostream>
#include <string>
#include "geometry.h"
using namespace std;

int main() {
    Vector3 point(1.0f, 2.0f, 3.0f);
    float norm = point.norm();
    point.print();
    cout << norm;
    string str;
    cin >> str;
    return 0;
}
