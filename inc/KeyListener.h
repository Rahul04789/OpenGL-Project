#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "Window.h"

namespace myproject
{
    namespace keylistener
    {
        class KeyListener
        {
        public:
            static bool m_keys[1024];
            static KeyListener* GetInstance(myproject::window::Window* window);
            void Initialize();
            static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
        private:
            static KeyListener* m_keyListener;
            KeyListener(myproject::window::Window* window = nullptr);

            myproject::window::Window* m_window;
        };
    }
}

#endif

