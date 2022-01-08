#include "geometry.h"

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
         * @brief Draws the triangle to the viewport
         */
        void drawTri(Tri tri) {
            
        }
};
