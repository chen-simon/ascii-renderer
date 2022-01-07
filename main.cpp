#include <iostream>
#include <string>
#include "geometry.h"
using namespace std;

int main() {
    Vector3 point = Vector3(1.0f, 2.0f, 3.0f);
    cout << point.x << endl;
    cout << point.y << endl;
    cout << point.z;
    string str;
    cin >> str;
    return 0;
}
