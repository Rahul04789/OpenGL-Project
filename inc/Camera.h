#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace myproject
{
    namespace camera
    {
        enum Camera_Movement
        {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };
        // Default camera values
        const GLfloat YAW        = -90.0f;
        const GLfloat PITCH      =  0.0f;
        const GLfloat SPEED      =  6.0f;
        const GLfloat SENSITIVTY =  0.25f;
        const GLfloat ZOOM       =  45.0f;

        class Camera
        {
            void updateCameraVectors();
        public:
            Camera( glm::vec3 position = glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3 up = glm::vec3( 0.0f, 1.0f, 0.0f ), GLfloat yaw = YAW, GLfloat pitch = PITCH );
            Camera( GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch );

            glm::mat4 GetViewMatrix();
            void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
            void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true);
            void ProcessMouseScroll(GLfloat yOffset);
            GLfloat GetZoom();
            void DoMovement(GLfloat& deltaTime);
            glm::vec3& GetPosition();
            glm::vec3 GetFront();
        private:
            // Camera Attributes
            glm::vec3 m_position;
            glm::vec3 m_front;
            glm::vec3 m_up;
            glm::vec3 m_right;
            glm::vec3 m_worldUp;

            // Eular Angles
            GLfloat m_yaw;
            GLfloat m_pitch;

            // Camera options
            GLfloat m_movementSpeed;
            GLfloat m_mouseSensitivity;
            GLfloat m_zoom;
        };
    }
}

#endif
