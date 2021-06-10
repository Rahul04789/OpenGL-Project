#include "Projection.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace projection = myproject::projection;

void projection::Projection::UpdateView(myproject::shader::Shader* pshader)
{
    GLint viewLoc = glGetUniformLocation(pshader->GetShaderProgram(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(m_view));
}
void projection::Projection::UpdateModel(myproject::shader::Shader* pshader)
{
    GLint modelLoc = glGetUniformLocation(pshader->GetShaderProgram(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m_model));
}
void projection::Projection::UpdateProjection(myproject::shader::Shader* pshader)
{
    GLint projLoc = glGetUniformLocation(pshader->GetShaderProgram(), "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(m_projection));
}
void projection::Projection::SetProjectionType(projection::PROJECTION_TYPE projtype)
{
    m_projectionType = projtype;
}
void projection::Projection::SetProjection(myproject::window::Window* window, myproject::camera::Camera* camera)
{
    auto ret = window->GetScreenWidthAndHeight();
    switch(m_projectionType)
    {
        case PROJECTION_PERSPECTIVE:
            {
                m_projection = glm::perspective( camera->GetZoom(), ( GLfloat )(ret.first) / ( GLfloat )(ret.second), 0.1f, 1000.0f );
                break;
            }
        case PROJECTION_ORTHOGRAPHIC:
            {
                m_projection = glm::ortho(0.0f, ( GLfloat )(ret.first), 0.0f, ( GLfloat )(ret.second), 0.1f, 1000.0f);
                break;
            }
        default:
            {
                break;
            }
    }
}
