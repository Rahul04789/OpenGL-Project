#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <vector>
//#include "Transform.h"
namespace myproject{namespace shader{class Shader;}}
#include "Projection.h"
#include "Camera.h"
#include "ConstantsObject.h"

namespace myproject
{
    namespace shader
    {
        class Shader
        {
        public:
            static GLuint CreateShader(const std::string& text, GLenum shaderType);
            Shader(const std::string & filename, std::string shaderName);
            void Bind();
            GLuint GetShaderProgram(){return m_program;}
            //void Update(const myproject::transform::Transform& transform);//it is going to update all the uniforms in the array to some new set of value.
            void UpdateFragmentShader(const std::vector<std::string>& uniformString,
                                      myproject::camera::Camera* camera,
                                      myproject::object::ObjectContainer& objContainer);
            void UpdateVertexShader(const std::vector<std::string>& uniformString,
                                    myproject::projection::Projection* projection,
                                    glm::vec3& LIGHTPOS);
            virtual ~Shader();
        private:
            Shader(const Shader& rhs){}
            void operator=(const Shader& rhs){}
            enum
            {
                VERTEX_SHADER,
                FRAGMENT_SHADER,
                NUM_SHADERS
            };
            enum
            {
                VIEW,
                PROJECTION,
                MODEL
            };
            GLuint m_program;//this is a handle. thats how we are going to refer to our shader program with openGL
            GLuint m_shaders[NUM_SHADERS];
            std::string m_shaderName;
            //GLuint m_uniforms[NUM_UNIFORMS];
        };
    }
}
#endif
