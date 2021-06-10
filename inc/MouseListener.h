#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include "Window.h"
#include "Camera.h"

namespace myproject
{
    namespace mouselistener
    {
        class MouseListener
        {
        public:
            static myproject::camera::Camera* m_camera;
            static MouseListener* GetInstance(myproject::window::Window* window);
            void Initialize();
            static void MouseCallback(GLFWwindow *window, double xPos, double yPos);
        private:
            static MouseListener* m_mouseListener;
            static GLfloat m_lastX;
            static GLfloat m_lastY;
            static bool m_firstMouse;
            
            MouseListener(myproject::window::Window* window = nullptr);

            myproject::window::Window* m_window;
        };
    }
}

#endif
