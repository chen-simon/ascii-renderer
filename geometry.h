#include <iostream>
#include <vector>
#include <math.h>

// Include Guard
#ifndef GEOMETRY
#define GEOMETRY

using namespace std;
using std::vector;

/**
 * @brief A vector in R3
 */
class Vector3
{
    public:
        float x;
        float y;
        float z;

        // Static vector operations

        /**
         * @brief Add v2 to v1
         */
        static Vector3 add(Vector3 v1, Vector3 v2)
        {
            float x = v1.x + v2.x;
            float y = v1.y + v2.y;
            float z = v1.z + v2.z;

            return Vector3(x, y, z); 
        }

        /**
         * @brief Returns v1 scaled by a scalar
         */
        static Vector3 times(float scalar, Vector3 v1)
        {
            float x = scalar * v1.x;
            float y = scalar * v1.y;
            float z = scalar * v1.z;

            return Vector3(x, y, z); 
        }

        /**
         * @brief Subtract v2 from v1
         */
        static Vector3 minus(Vector3 v1, Vector3 v2)
        {
            return add(v1, times(-1, v2)); 
        }

                /**
         * @brief Return the dot product of two vectors
         */
        static float dot(Vector3 v1, Vector3 v2)
        {
            return v1.x * v1.x + v1.y * v2.y + v1.z * v2.z;
        }

        /**
         * @brief Return the cross product of two vectors
         */
        static Vector3 cross(Vector3 v1, Vector3 v2)
        {
            float x = v1.y * v2.z - v1.z * v2.y;
            float y = v1.z * v2.x - v1.x * v2.z;
            float z = v1.x * v2.y - v1.y * v2.x;

            return Vector3(x, y, z);
        }

        // Instance vector operations

        /**
         * @brief Returns the norm of the vector
         */
        float norm()
        {
            return sqrt(x * x + y * y + z * z);
        }

        /**
         * @brief Normalize the vector to a unit vector
         */
        void normalize()
        {
            float n = norm();

            if (n == 0)
        {
                return;
            }

            x = x / n;
            y = y / n;
            z = z / n;
        }

        /**
         * @brief Print the vector to console
         */
        void print()
        {
            cout << "(" << x << ", " << y << ", "  << z << ")" << endl;
        }

        // Constructors
        Vector3 ()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        Vector3(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
};


/**
 * @brief A line in R3
 */
class Line
{
    public:
        Vector3 d;
        Vector3 p;
    
        static Line getLine(Vector3 p1, Vector3 p2)
        {
            return Line(Vector3::minus(p2, p1), p1);
        }

        Line(Vector3 d, Vector3 p)
        {
            this->d = d;
            this->p = p;
        }
};


/**
 * @brief A plane in R3
 */
class Plane
{
    public:
        Vector3 d1;
        Vector3 d2;
        Vector3 p;

        /**
         * @brief Return a tangent plane given a normal vector
         */
        static Plane getTangentPlane(Line line)
        {
            Vector3 a = Vector3(0.0f, 1.0f, 0.0f);
            // Edge case
            if (line.d.z == 0)
            {
                a = Vector3(0.0f, 0.0f, 1.0f);
            }
            else
            {
                // General case
                a.z = -line.d.y / line.d.z;
            }
            Vector3 b = Vector3::cross(a, line.d);
            
            return Plane(a, b, line.p);
        }

        /**
         * @brief Return a normal vector of the plane
         */
        Vector3 norm()
        {
            return Vector3::cross(d1, d2);
        }

        /**
         * @brief Return the intersection point between a line and a plane;
         */
        Vector3 lineIntersection(Line line)
        {
            Vector3 n = norm();
            float numerator = (Vector3::dot(n, line.p) - n.x * line.p.x - n.y * line.p.y - n.z * line.p.z);
            float denominator = (n.x * line.d.x + n.y * line.d.y + n.z * line.d.z);

            // Edge case
            if (denominator == 0)
        {
                return Vector3();
            }

            // Solve for t
            float t = numerator / denominator;
            
            return Vector3::add(line.p, Vector3::times(t, line.d));
        }

        Plane()
        {
            d1 = Vector3(1.0f, 0.0f, 0.0f);
            d2 = Vector3(0.0f, 1.0f, 0.0f);
            p = Vector3(0.0f, 0.0f, 0.0f);
        }

        Plane(Vector3 d1, Vector3 d2, Vector3 p)
        {
            this->d1 = d1;
            this->d2 = d2;
            this->p = p;
        }
};

/**
 * @brief A triangular face in R3
 */
class Tri
{
    public:
        Vector3 p[3];
    
        Tri(Vector3 p1, Vector3 p2, Vector3 p3)
        {
            p[0] = p1;
            p[1] = p2;
            p[2] = p3;
        }

        /**
         * @brief Return the surface normal of the tri
         */
        Vector3 norm()
        {
            Vector3 d1 = Vector3::minus(p[1], p[0]);
            Vector3 d2 = Vector3::minus(p[2], p[0]);
            
            Vector3 norm = Vector3::cross(d1, d2);
            norm.normalize();
            return norm;
        }
};

/**
 * @brief A 3D object
 */
class Object
{
    public:
        Vector3 position;
        Vector3 rotation;
        vector<Tri> tris;

        Object()
        {
            
        }

        Object(vector<Tri> tris)
        {
            this->tris = tris;
        }
};

#endif /* GEOMETRY */