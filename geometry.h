#include <vector>

using std::vector;

/**
 * @brief A vector in R3
 */
class Vector3 {
    public:
        float x;
        float y;
        float z;

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