#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace myproject
{
    namespace window
    {
        class Window
        {
            GLFWwindow* m_window;
            int m_screenWidth;
            int m_screenHeight;
        public:
            Window(const int& width, const int& height, std::string title);
            ~Window();
            bool IsClosed();
            void Clear(float r, float g, float b, float a);
            void Update();
            std::pair<int, int> GetScreenWidthAndHeight();
            GLFWwindow* GetWindow();
        private:
            Window(const Window& rhs) = default;
            Window& operator=(const Window& rhs) = default;
        };
    }    
} // namespace myproject

#endif
