#include "KeyListener.h"
#include <iostream>

namespace keylstnr = myproject::keylistener;
//static variable definition
keylstnr::KeyListener* keylstnr::KeyListener::m_keyListener{nullptr};
bool keylstnr::KeyListener::m_keys[1024];

keylstnr::KeyListener::KeyListener(myproject::window::Window* window):m_window(window)
{

}
keylstnr::KeyListener* keylstnr::KeyListener::GetInstance(myproject::window::Window* window)
{
    if(m_keyListener == nullptr)
    {
        m_keyListener = new KeyListener(window);
    }
    return m_keyListener;
}
void keylstnr::KeyListener::KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode )
{
    //std::cout<<"Key entered is: "<<key<<std::endl;
    if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }    
    if(key >= 0 && key < 1024)
    {
        if(action == GLFW_PRESS)
        {
            m_keys[key] = true;
        }
        else if(action == GLFW_RELEASE)
        {
            m_keys[key] = false;
        }
    }
}
void keylstnr::KeyListener::Initialize()
{
    glfwSetKeyCallback(m_window->GetWindow(), KeyCallback);
}
