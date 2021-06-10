#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

namespace myproject
{
    namespace display
    {
        class Display
        {
        public:
            Display(int width, int height, const std::string& title);
            virtual ~Display();
            void Update();
            bool IsClosed();
            void Clear(float r, float g, float b, float a);
        private:
            Display(const Display& rhs){}
            void operator=(const Display& rhs){}

            SDL_Window* m_window;
            SDL_GLContext m_glContext;
            bool m_isClosed;
        };
    }
}

#endif
