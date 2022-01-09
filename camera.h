#include "geometry.h"
using namespace std;

// The light levels of a surface in ASCII-Characters
const static char LIGHT_LEVELS [] = {'@', '#', 'X', 'k', 'O', 'z', '/', '-', ':', '~', '`'};

/**
 * @brief A 2-dimensional vector (used for rendering on screen)
 */
class Vector2 {
    public:
        float x;
        float y;

        Vector2 copy() {
            return Vector2(x, y);
        }

        Vector2() {
            x = 0;
            y = 0;
        }

        Vector2(float x, float y) {
            this->x = x;
            this->y = y;
        }

        Vector2(Vector3 v) {
            x = v.x;
            y = v.y;
        }
};

/**
 * @brief The camera viewport
 */
class Camera {
    public:
        Vector3 position;
        Vector3 rotation;
        float focalLength;
        float width;
        float height;

        Plane viewport;
    
        /**
         * @brief Calculate the viewport plane.
         */
        void calculateViewport() {
            Plane tangentPlane = Plane::getTangentPlane(Line(rotation, position));
            tangentPlane.p = Vector3::add(position, Vector3::times(focalLength, rotation));
            viewport = tangentPlane;
        }

        Camera() {
            // Default camera values
            position = Vector3(0.0f, 0.0f, -10.0f);
            rotation = Vector3();
            focalLength = 1;
            width = 10;
            height = 3;
            viewport = Plane(Vector3(1.0f, 0.0f, 0.0f),
                            Vector3(0.0f, 1.0f, 0.0f),
                            Vector3(0.0f, 0.0f, -9.0f));
        }

        /**
         * @brief Get the light level of a surface given its norm
         */
        char getLightLevel(Vector3 norm) {
            
        }

        /**
         * @brief Draws the triangle to the viewport
         */
        void drawTri(Tri tri) {
            Vector3 n = tri.norm();

            // Guard clause to prevent drawing faces in the wrong direction
            if (Vector3::dot(rotation, n) <= 0) {
                return;
            }

            // Screen points
            Vector2 p[3];

            for (int i = 0; i < 3; i++) {
                // Project world point to view plane
                Line line(Vector3::minus(tri.p[i], position), position);
                Vector3 point = viewport.lineIntersection(line);

                // Implicit cast to xy-plane
                p[i] = Vector2(point);
            }

            // Render screen points
            scanlineRender(p);
        }

        /**
         * @brief Draw the a triangle given 3 viewplane coordinates
         */
        void scanlineRender(Vector2 p[]) {
            // order by height
            swapPoints(p, 0, 1);
            swapPoints(p, 1, 2);
            
            // draw top half

            // draw bottom half
        }

        /**
         * @brief Swap two 2D points given their viewport height by ascending
         */
        void swapPoints(Vector2 p[], int a, int b) {
            if (p[a].y < p[b].y) {
                Vector2 temp = p[a].copy();
                p[a] = p[b];
                p[b] = temp;
            }
        }
};
