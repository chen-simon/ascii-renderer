#include <iostream>
#include <string>
#include "geometry.h"
using namespace std;

int main() {
    Vector3 point(1.0f, 2.0f, 3.0f);
    Vector3 p2 = Vector3::times(-1.0f, point);
    Vector3 p3 = Vector3::minus(point, p2);

    point.print();
    cout << point.norm();
    point.normalize();
    cout << point.norm();
    point.print();
    p3.print();
    string str;
    cin >> str;
    return 0;
}
