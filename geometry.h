#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using std::vector;

/**
 * @brief A vector in R3
 */
class Vector3 {
    public:
        float x;
        float y;
        float z;

        // Static vector operations
        static Vector3 add(Vector3 v1, Vector3 v2) {
            float x = v1.x + v2.x;
            float y = v1.y + v2.y;
            float z = v1.z + v2.z;

            return Vector3(x, y, z); 
        }

        static Vector3 times(float scalar, Vector3 v1) {
            float x = scalar * v1.x;
            float y = scalar * v1.y;
            float z = scalar * v1.z;

            return Vector3(x, y, z); 
        }

        static Vector3 minus(Vector3 v1, Vector3 v2) {
            return add(v1, times(-1, v2)); 
        }

        // Instance vector operations
        float norm() {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * @brief Print the vector to console
         */
        void print() {
            cout << "(" << x << ", " << y << ", "  << z << ")" << endl;
        }

        // Constructors
        Vector3 () {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        Vector3(int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

/**
 * @brief A triangular face in R3
 */
class Tri {
    public:
        Vector3 p1;
        Vector3 p2;
        Vector3 p3;
    
        Tri(Vector3 p1, Vector3 p2, Vector3 p3) {
            this->p1 = p1;
            this->p2 = p2;
            this->p3 = p3;
        }

        Vector3 norm() {
            Vector3 d1 = Vector3::minus(p1, p2);
            Vector3 d2 = Vector3::minus(p2, p3);
        }
};

/**
 * @brief A 3D object
 */
class Object {
    public:
        vector<Tri> tris;

        Object(vector<Tri> tris) {
            this->tris = tris;
        }
};

/**
 * @brief The camera viewport
 */
class Camera {
    public:
        Vector3 position;
        Vector3 rotation;
        float width;
        float height;
    
        Camera() {
            // Default camera values
            position = Vector3();
            rotation = Vector3();
            width = 10;
            height = 3;
        }
};