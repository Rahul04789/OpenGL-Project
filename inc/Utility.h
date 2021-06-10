#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <GL/glew.h>
namespace myproject
{
    namespace utility
    {
        class Utility
        {
        public:
            static std::string LoadShader(const std::string& fileName);
            static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
        };
    }
}

#endif
