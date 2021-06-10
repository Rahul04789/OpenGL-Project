#include "Mesh.h"
#include "Constants.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mesh = myproject::mesh;

mesh::Mesh::Mesh(const GLfloat *vertices, const unsigned int& vertecessize)
{
    m_drawCount = 3;//numVertices;
    glGenBuffers(1, &m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers);
    glBufferData(GL_ARRAY_BUFFER, vertecessize, vertices, GL_STATIC_DRAW);
    for(int e = myproject::mesh::LIGHTING_VAO; e < myproject::mesh::NUM_BUFFERS; ++e)
    {
        glGenVertexArrays(1, &m_vertexArrayObject[e]);//created space for vertexArray.
        glBindVertexArray(m_vertexArrayObject[e]);
        if(e != myproject::mesh::LIGHTING_VAO)
            glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( GLfloat ), ( GLvoid * )0);
        glEnableVertexAttribArray(0);
        if(e == myproject::mesh::LIGHTING_VAO)// || e == myproject::mesh::LINE_VAO)
        {
            //Normal Attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( GLfloat ), ( GLvoid * )(3*sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        
            //texture
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof( GLfloat ), ( GLvoid * )(6*sizeof(GLfloat)));
            glEnableVertexAttribArray(2);
        }
        glBindVertexArray(0);
    }
}
mesh::Mesh::~Mesh()
{
    for(int e = myproject::mesh::LIGHTING_VAO; e < myproject::mesh::NUM_BUFFERS; ++e)
    {
        glDeleteVertexArrays(1, &m_vertexArrayObject[e]);        
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &m_vertexArrayBuffers);
}
void mesh::Mesh::DrawLight(myproject::projection::Projection* projection, myproject::shader::Shader* shader)
{
    const glm::vec3 cubePositions[] = {
            glm::vec3(  0.0f,   0.0f,   0.0f),  glm::vec3(  2.0f,   5.0f,   -15.0f),
            glm::vec3(  -1.5f,  -2.2f,  -2.5f), glm::vec3(  -3.8f,  -2.0f,  -12.3f),
            glm::vec3(  2.4f,   -0.4f,  -3.5f), glm::vec3(  -1.7f,  3.0f,   -7.5f),
            glm::vec3(  1.3f,   -2.0f,  -2.5f), glm::vec3(  1.5f,   2.0f,   -2.5f),
            glm::vec3(  1.5f,   0.2f,   -1.5f), glm::vec3(  -1.3f,  1.0f,   -1.5f)
        };
    glBindVertexArray(m_vertexArrayObject[LIGHTING_VAO]);
    glm::mat4 model;
    for(GLuint i=0;i<10;++i)
    {
        model = glm::mat4( );
        model = glm::translate(model, cubePositions[i]);
        GLfloat angle = 20.0f * i;
        model = glm::rotate( model, angle, glm::vec3( 1.0f, 0.3f, 0.5f ) );
        GLint modelLoc = glGetUniformLocation(shader->GetShaderProgram(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);
}

void mesh::Mesh::DrawLamp(myproject::projection::Projection* projection, myproject::shader::Shader* shader)
{
    glBindVertexArray(m_vertexArrayObject[LAPM_VAO]);
    glDrawArrays( GL_TRIANGLES, 0, 36 );
    glBindVertexArray(0);
}

void mesh::Mesh::DrawLine(myproject::projection::Projection* projection, myproject::shader::Shader* shader)
{
    glBindVertexArray(m_vertexArrayObject[LINE_VAO]);
    glDrawArrays( GL_LINES, 0, 6 );
    glBindVertexArray(0);
}
