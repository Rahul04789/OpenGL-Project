#include "Utility.h"
#include <fstream>
#include <iostream>

namespace utlty = myproject::utility;

std::string utlty::Utility::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());
    std::cout<<fileName<<std::endl;
    std::string output, line;
    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr<<"Unable to load shader: "<<fileName<<std::endl;
    }
    return output;
}
void utlty::Utility::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = {0};

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);
    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr<<errorMessage<<": '"<<error<<"'"<<std::endl;
    }
}