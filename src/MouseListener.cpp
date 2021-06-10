#include "MouseListener.h"
#include "Constants.h"
#include <iostream>

namespace mouselstnr = myproject::mouselistener;
//static variable definition
mouselstnr::MouseListener* mouselstnr::MouseListener::m_mouseListener{nullptr};
GLfloat                    mouselstnr::MouseListener::m_lastX;
GLfloat                    mouselstnr::MouseListener::m_lastY;
bool                       mouselstnr::MouseListener::m_firstMouse{true};
myproject::camera::Camera*     mouselstnr::MouseListener::m_camera{nullptr};

mouselstnr::MouseListener::MouseListener(myproject::window::Window* window):m_window(window)
{
    m_lastX = myproject::window::WIDTH / 2.0;
    m_lastY = myproject::window::HEIGHT / 2.0;
}
mouselstnr::MouseListener* mouselstnr::MouseListener::GetInstance(myproject::window::Window* window)
{
    if(m_mouseListener == nullptr)
    {
        m_mouseListener = new MouseListener(window);
    }
    return m_mouseListener;
}
void mouselstnr::MouseListener::MouseCallback(GLFWwindow *window, double xPos, double yPos)
{
    //std::cout<<""<<xPos<<" : "<<yPos<<std::endl;
    if( m_firstMouse )
    {
        m_lastX = xPos;
        m_lastY = yPos;
        m_firstMouse = false;
    }
    
    GLfloat xOffset = xPos - m_lastX;
    GLfloat yOffset = m_lastY - yPos;  // Reversed since y-coordinates go from bottom to left
    
    m_lastX = xPos;
    m_lastY = yPos;
    
    m_camera->ProcessMouseMovement(xOffset, yOffset);
}

void mouselstnr::MouseListener::Initialize()
{
    glfwSetCursorPosCallback(m_window->GetWindow(), MouseCallback);
}

