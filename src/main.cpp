#include <iostream>
#include <string>
#include "geometry.hpp"
#include "camera.hpp"
using namespace std;

int main()
{
    Camera camera = Camera();
    camera.renderScreen();

    string str;
    cin >> str;
    return 0;
}
