#include "Window.h"
#include <iostream>
#include <stdlib.h>

namespace win = myproject::window;

win::Window::Window(const int& width, const int& height, std::string title)
{
    // Init GLFW
    glfwInit( );
    
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );

    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );

    m_window = glfwCreateWindow( width, height, title.c_str(), nullptr, nullptr );
    
    glfwGetFramebufferSize( m_window, &m_screenWidth, &m_screenHeight );

    if ( nullptr == m_window )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate( );
        return ;
    }
    glfwMakeContextCurrent( m_window );

    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return ;
    }
    // Define the viewport dimensions
    glViewport( 0, 0, m_screenWidth, m_screenHeight );
}
GLFWwindow* win::Window::GetWindow()
{
    return m_window;
}
std::pair<int, int> win::Window::GetScreenWidthAndHeight()
{
    return {m_screenWidth, m_screenHeight};
}
void win::Window::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//to clear the depth buffer bit
}
void win::Window::Update()
{
    // Swap the screen buffers
    glfwSwapBuffers( m_window );
    glfwPollEvents();
}
bool win::Window::IsClosed()
{
    return glfwWindowShouldClose( m_window );
}

win::Window::~Window()
{
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate( );
}
