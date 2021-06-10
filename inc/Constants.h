#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>
#include <vector>

namespace myproject
{
    namespace window
    {
        const static int WIDTH         = 1366;//1920;//800;
        const static int HEIGHT        = 768;//1080;//600;
        const static std::string TITLE = "MyProjectOpenGL";
    }
    namespace shader
    {
        const static std::string SHADER1 = "./res/Shader/lighting";
        const static std::string SHADER2 = "./res/Shader/lamp";
        const static std::string SHADER3 = "./res/Shader/line";
        const static std::string SHADER4 = "./res/Shader/modelLoading";
    }
    namespace model
    {
        const static std::string MODEL1 = "./res/models/player/nanosuit.obj";
        const static std::string MODEL2 = "./res/models/room/EmptyRoom(OBJ).obj";
    }
    namespace fragmentshader_uniform_variables
    {
        const std::vector<std::string> FS_UV{"light.m_position",    "light.m_ambient",
                                             "light.m_diffuse",     "light.m_specular",
                                             "light.m_constant",    "light.m_linear",
                                             "light.m_quadratic",   "material.m_diffuse",
                                             "material.m_specular", "material.m_shininess",
                                             "viewPos",             "light.m_direction",
                                             "light.m_cutOff",      "light.m_outerCutOff"};
        enum FSUV
        {
            LIGHT_POSITION, LIGHT_AMBIENT, LIGHT_DIFFUSE,   LIGHT_SPECULAR,
            LIGHT_CONSTANT, LIGHT_LINEAR,  LIGHT_QUADRATIC, MATERIAL_DIFFUSE,
            MATERIAL_SPECULAR, MATERIAL_SHININESS, VIEWPOS, LIGHT_DIRECTION,
            LIGHT_CUTOFF,   LIGHT_OUTERCUTOFF
        };
    }
    namespace vertexshader_uniform_variables
    {
        const std::vector<std::string> VS_UV{"view", "projection", "model"};
    }
    
    namespace image
    {
        const static std::string IMAGE1 = "./res/images/image1.jpg";
        const static std::string IMAGE2 = "./res/images/image2.png";
        const static std::string IMAGE3 = "./res/images/image3.png";
        const static std::string IMAGE4 = "./res/images/ABC.png";
        const static std::string IMAGE5 = "./res/images/container2.png";
        const static std::string IMAGE6 = "./res/images/container2_specular.png";
        const static std::string IMAGE7 = "./res/images/matrix.jpg";
    }
    namespace vertices
    {
        // use with Perspective Projection
        const GLfloat vertices[] =
        {/*
            0.0f,  0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
            0.0f,  1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
            0.0f,  0.0f, 0.0f,  0.0f, 1.0f, 0.0f,
            10.0f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f,
            0.0f,  0.0f, 0.0f,  0.0f, 0.3f, 1.0f,
            0.0f,  0.0f, 1.0f,  1.0f, 0.3f, 0.0f*/
            // Positions            // Normals              // Texture Coords
            -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
            0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
            -0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  1.0f,
            -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,
            
            -0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,
            0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  1.0f,
            0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,  	1.0f,  1.0f,
            -0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,
            
            -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  1.0f,
            -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
            -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
            -0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,
            
            0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  1.0f,
            0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
            0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
            0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  0.0f,
            0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,
            
            -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,
            0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  1.0f,
            0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,
            
            -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f,
            0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  1.0f,
            0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f
        };       
        const unsigned int vertecessize = sizeof(vertices); 
    }
}

#endif
