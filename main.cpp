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

    string str;
    cin >> str;
    return 0;
}
