#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include "Shader_old.h"

namespace myproject
{
    namespace texture
    {
        class Texture
        {
        public:
            Texture(std::string fileName, std::string texName);
            void Update(myproject::shader::Shader* pshader, std::string texName);
        private:
            Texture(const Texture& rhs){}
            void operator=  (const Texture& rhs){}

            GLuint      m_texture;
            std::string m_texName;
        };
    }
}

#endif
