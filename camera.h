#include "geometry.h"

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
