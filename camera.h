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
    
        Camera() {
            // Default camera values
            position = Vector3();
            rotation = Vector3();
            focalLength = 1;
            width = 10;
            height = 3;
        }

        /**
         * @brief Draws the triangle to the viewport
         */
        void drawTri(Tri tri) {
            
        }
};
