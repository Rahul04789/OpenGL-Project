#include "Camera.h"
#include "KeyListener.h"

namespace camera = myproject::camera;

// Constructor with vectors
camera::Camera::Camera( glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed( SPEED ), m_mouseSensitivity( SENSITIVTY ), m_zoom( ZOOM )
{
    this->m_position = position;
    this->m_worldUp = up;
    this->m_yaw = yaw;
    this->m_pitch = pitch;
    this->updateCameraVectors( );
}

// Constructor with scalar values
camera::Camera::Camera( GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(SPEED), m_mouseSensitivity(SENSITIVTY), m_zoom(ZOOM)
{
    this->m_position = glm::vec3( posX, posY, posZ );
    this->m_worldUp = glm::vec3( upX, upY, upZ );
    this->m_yaw = yaw;
    this->m_pitch = pitch;
    this->updateCameraVectors();
}

// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
glm::mat4 camera::Camera::GetViewMatrix()
{
    return glm::lookAt( this->m_position, this->m_position + this->m_front, this->m_up );
    //position, target and up vector 
}
glm::vec3& camera::Camera::GetPosition()
{
    return m_position;
}
glm::vec3 camera::Camera::GetFront()
{
    return this->m_front;
}
// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void camera::Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
{
    GLfloat velocity = this->m_movementSpeed * deltaTime;
    
    if ( direction == FORWARD )
    {
        this->m_position += this->m_front * velocity;
    }
    
    if ( direction == BACKWARD )
    {
        this->m_position -= this->m_front * velocity;
    }
    
    if ( direction == LEFT )
    {
        this->m_position -= this->m_right * velocity;
    }
    
    if ( direction == RIGHT )
    {
        this->m_position += this->m_right * velocity;
    }
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void camera::Camera::ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch)
{
    xOffset *= this->m_mouseSensitivity;
    yOffset *= this->m_mouseSensitivity;
    
    this->m_yaw   += xOffset;
    this->m_pitch += yOffset;
    
    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if ( constrainPitch )
    {
        if ( this->m_pitch > 89.0f )
        {
            this->m_pitch = 89.0f;
        }
        
        if ( this->m_pitch < -89.0f )
        {
            this->m_pitch = -89.0f;
        }
    }
    
    // Update Front, Right and Up Vectors using the updated Eular angles
    this->updateCameraVectors( );
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void camera::Camera::ProcessMouseScroll( GLfloat yOffset )
{
    if(this->m_zoom >= 1.0f && this->m_zoom <= 45.0f)
    {
        this->m_zoom -= yOffset;
    }    
    if(this->m_zoom <= 1.0f)
    {
        this->m_zoom = 1.0f;
    }    
    if(this->m_zoom >= 45.0f)
    {
        this->m_zoom = 45.0f;
    }
}

void camera::Camera::DoMovement(GLfloat& deltaTime)
{
    // Camera controls
    if(myproject::keylistener::KeyListener::m_keys[GLFW_KEY_W] || 
       myproject::keylistener::KeyListener::m_keys[GLFW_KEY_UP] )
    {
        ProcessKeyboard( FORWARD, deltaTime );
    }    
    if(myproject::keylistener::KeyListener::m_keys[GLFW_KEY_S] ||
       myproject::keylistener::KeyListener::m_keys[GLFW_KEY_DOWN] )
    {
        ProcessKeyboard( BACKWARD, deltaTime );
    }    
    if(myproject::keylistener::KeyListener::m_keys[GLFW_KEY_A] || 
       myproject::keylistener::KeyListener::m_keys[GLFW_KEY_LEFT] )
    {
        ProcessKeyboard( LEFT, deltaTime );
    }    
    if(myproject::keylistener::KeyListener::m_keys[GLFW_KEY_D] || 
       myproject::keylistener::KeyListener::m_keys[GLFW_KEY_RIGHT] )
    {
        ProcessKeyboard( RIGHT, deltaTime );
    }
}
GLfloat camera::Camera::GetZoom()
{
    return this->m_zoom;
}    

// Calculates the front vector from the Camera's (updated) Eular Angles
void camera::Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos( glm::radians( this->m_yaw ) ) * cos( glm::radians( this->m_pitch ) );
    front.y = sin( glm::radians( this->m_pitch ) );
    front.z = sin( glm::radians( this->m_yaw ) ) * cos( glm::radians( this->m_pitch ) );
    this->m_front = glm::normalize( front );
    // Also re-calculate the Right and Up vector
    this->m_right = glm::normalize( glm::cross( this->m_front, this->m_worldUp ) );  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    this->m_up = glm::normalize( glm::cross( this->m_right, this->m_front ) );
}
