#include "Shader_old.h"
#include "Utility.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace shdr  = myproject::shader;
namespace utlty = myproject::utility;

shdr::Shader::Shader(const std::string & fileName, std::string shaderName):m_shaderName(shaderName)
{
    glewExperimental           = GL_TRUE;
    m_program                  = glCreateProgram();
    m_shaders[VERTEX_SHADER]   = CreateShader(utlty::Utility::LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[FRAGMENT_SHADER] = CreateShader(utlty::Utility::LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i=0; i<NUM_SHADERS; ++i)
    {
        glAttachShader(m_program, m_shaders[i]);
    }
    glBindAttribLocation(m_program, 0, "position");

    glLinkProgram(m_program);
    utlty::Utility::CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader Program Linking failed. ");

    glValidateProgram(m_program);
    utlty::Utility::CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Shader Program is invalid. ");
}
GLuint shdr::Shader::CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    if(shader == 0)
        std::cerr<<"Error: Shader creation failed."<<std::endl;
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLengths[1];
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLengths[0]=text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);

    utlty::Utility::CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader Compilation failed. ");

    return shader;
}
void shdr::Shader::Bind()
{
    glUseProgram(m_program);
}
void shdr::Shader::UpdateFragmentShader(const std::vector<std::string>& uniformString,
                                        myproject::camera::Camera* camera,
                                        myproject::object::ObjectContainer& objContainer)
{
    /*
    "light.m_position",    "light.m_ambient",
    "light.m_diffuse",     "light.m_specular",
    "light.m_constant",    "light.m_linear",
    "light.m_quadratic",   "material.m_diffuse",
    "material.m_specular", "material.m_shininess",
    "viewPos",             "light.m_direction",
    "light.m_cutOff",      "light.m_outerCutOff"
    */
    std::vector<GLint> loc;
    for(auto& str : uniformString)
    {
        loc.push_back(glGetUniformLocation(m_program, str.c_str()));
    }
    using namespace myproject::fragmentshader_uniform_variables;
    glUniform3f(loc[LIGHT_POSITION], objContainer.GetObject()[0]->Get().x, //light.m_position
                                     objContainer.GetObject()[0]->Get().y,
                                     objContainer.GetObject()[0]->Get().z);
    glUniform3f(loc[LIGHT_AMBIENT], objContainer.GetObject()[0]->GetAmbient().x, //light.m_ambient
                                    objContainer.GetObject()[0]->GetAmbient().y,
                                    objContainer.GetObject()[0]->GetAmbient().z);
    glUniform3f(loc[LIGHT_DIFFUSE], objContainer.GetObject()[0]->GetDiffuse().x, //light.m_diffuse
                                    objContainer.GetObject()[0]->GetDiffuse().y,
                                    objContainer.GetObject()[0]->GetDiffuse().z);
    glUniform3f(loc[LIGHT_SPECULAR], objContainer.GetObject()[0]->GetSpecular().x,//light.m_specular
                                     objContainer.GetObject()[0]->GetSpecular().y,
                                     objContainer.GetObject()[0]->GetSpecular().z);
    glUniform1f(loc[LIGHT_CONSTANT],     1.0f );//light.m_constant
    glUniform1f(loc[LIGHT_LINEAR],       0.09f);//light.m_linear
    glUniform1f(loc[LIGHT_QUADRATIC],    0.032f );//light.m_quadratic
    glUniform1i(loc[MATERIAL_DIFFUSE],   0 );    //material.m_diffuse
    glUniform1i(loc[MATERIAL_SPECULAR],  1 );    //material.m_specular
    glUniform1f(loc[MATERIAL_SHININESS], 32.0f );//material.m_shininess
    glUniform3f(loc[VIEWPOS], camera->GetPosition().x, camera->GetPosition().y, camera->GetPosition().z);//viewPos
    glUniform3f(loc[LIGHT_DIRECTION], camera->GetFront().x, camera->GetFront().y, camera->GetFront().z);//light.m_direction
    glUniform1f(loc[LIGHT_CUTOFF], glm::cos(glm::radians(12.5f)));//light.m_cutOff
    glUniform1f(loc[LIGHT_OUTERCUTOFF], glm::cos(glm::radians(17.5f)));//light.m_outerCutOff
}
void shdr::Shader::UpdateVertexShader(const std::vector<std::string>& uniformString,
                                      myproject::projection::Projection* projection,
                                      glm::vec3& LIGHTPOS)
{
    glm::mat4 model;
    std::vector<GLint> loc;
    for(auto& str : uniformString)
    {
        loc.push_back(glGetUniformLocation(m_program, str.c_str()));
    }
    if(m_shaderName.compare("lamp")==0 || m_shaderName.compare("modelcharactor")==0)
    {
        model = glm::mat4();
        model = glm::translate(model, LIGHTPOS);
        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
        //model = glm::rotate(model, (GLfloat)glfwGetTime() * -0.8f, glm::vec3(0.0f, 0.0f, 1.0f));
    }
    glUniformMatrix4fv(loc[VIEW],       1, GL_FALSE, glm::value_ptr(projection->GetView()));
    glUniformMatrix4fv(loc[PROJECTION], 1, GL_FALSE, glm::value_ptr(projection->GetProjection()));
    glUniformMatrix4fv(loc[MODEL],      1, GL_FALSE, glm::value_ptr(model));
}
shdr::Shader::~Shader()
{
    for(unsigned int i=0; i<NUM_SHADERS; ++i)
    {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}
