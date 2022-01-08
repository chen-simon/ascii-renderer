#include <iostream>
#include <string>
#include "geometry.h"
using namespace std;

int main() {
    Vector3 p1(1.0f, 0.0f, 0.0f);
    Vector3 p2(0.0f, 2.0f, 0.0f);
    Vector3 p3(0.0f, 0.0f, 1.0f);

    Tri tri(p1, p2, p3);
    Vector3 norm = tri.norm();
    norm.print();
    Line line(norm, p1);
    Plane plane = Plane::getTangentPlane(line);
    plane.d1.print();
    plane.d2.print();

    cout << endl;
    
    Vector3 p4(0.667f, 0.333f, 0.667f);
    Vector3 p5(0.0f, 1.0f, -0.5f);
    Vector3 ee = Vector3::cross(p5, p4);
    ee.print();

    cout << endl;
    
    Vector3 p6(1.0f, 2.0f, 3.0f);
    Vector3 p7(2.0f, 3.0f, -1.0f);
    Vector3 eee = Vector3::cross(p6, p7);
    eee.print();

    string str;
    cin >> str;
    return 0;
}
