#ifndef SCROLLLISTENER_H
#define SCROLLLISTENER_H

#include "Window.h"
#include "Camera.h"

namespace myproject
{
    namespace scrolllistener
    {
        class ScrollListener
        {
        public:
            static myproject::camera::Camera* m_camera;
            static ScrollListener* GetInstance(myproject::window::Window* window);
            void Initialize();
            static void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
        private:
            static ScrollListener* m_scrollListener;
            ScrollListener(myproject::window::Window* window = nullptr);

            myproject::window::Window* m_window;
        };
    }
}

#endif
