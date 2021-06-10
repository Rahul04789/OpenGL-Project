#include "ScrollListener.h"
#include "Constants.h"
#include <iostream>

namespace scrolllstnr = myproject::scrolllistener;
//static variable definition
scrolllstnr::ScrollListener* scrolllstnr::ScrollListener::m_scrollListener{nullptr};
myproject::camera::Camera* scrolllstnr::ScrollListener::m_camera{nullptr};

scrolllstnr::ScrollListener::ScrollListener(myproject::window::Window* window)
                                            :m_window(window)
{
}
scrolllstnr::ScrollListener* scrolllstnr::ScrollListener::GetInstance(myproject::window::Window* window)
{
    if(m_scrollListener == nullptr)
    {
        m_scrollListener = new ScrollListener(window);
    }
    return m_scrollListener;
}
void scrolllstnr::ScrollListener::ScrollCallback(GLFWwindow *window, double xOffset, double yOffset)
{
    std::cout<<"Scrolling"<<std::endl;
    m_camera->ProcessMouseScroll(yOffset);
}

void scrolllstnr::ScrollListener::Initialize()
{
    glfwSetScrollCallback(m_window->GetWindow(), ScrollCallback);
}

