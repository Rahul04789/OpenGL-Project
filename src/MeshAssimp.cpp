#include "MeshAssimp.h"

namespace mesh = myproject::meshassimp;

mesh::Mesh::Mesh(std::vector<Vertex>  vertices,
                 std::vector<GLuint>  indices,
                 std::vector<Texture> textures)
{
    this->m_vertices = vertices;
    this->m_indices  = indices;
    this->m_textures = textures;
    this->SetUpMesh();
}
void mesh::Mesh::Draw(myproject::shader::Shader* shader)
{
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    for(GLuint i = 0; i < this->m_textures.size(); ++i)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        std::stringstream ss;
        std::string       number;
        std::string       name = m_textures[i].m_type;
        if("texture_diffuse" == name)
        {
            ss << diffuseNr++;
        }
        else if("texture_specular" == name)
        {
            ss << specularNr++;
        }
        number = ss.str();
        glUniform1i(glGetUniformLocation(shader->GetShaderProgram(), (name+number).c_str()), i);
        glBindTexture(GL_TEXTURE_2D, m_textures[i].m_id);
    }
    glUniform1f(glGetUniformLocation(shader->GetShaderProgram(), "material.m_shininess"), 16.0f);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    for(GLuint i = 0; i < this->m_textures.size(); ++i)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}
void mesh::Mesh::SetUpMesh()
{
    // Create buffers/arrays
    glGenVertexArrays( 1, &this->VAO );
    glGenBuffers( 1, &this->VBO );
    glGenBuffers( 1, &this->EBO );
    
    glBindVertexArray( this->VAO );
    // Load data into vertex buffers
    glBindBuffer( GL_ARRAY_BUFFER, this->VBO );
    // A great thing about structs is that their memory layout is sequential for all its items.
    // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
    // again translates to 3/2 floats which translates to a byte array.
    glBufferData( GL_ARRAY_BUFFER, this->m_vertices.size( ) * sizeof( Vertex ), &this->m_vertices[0], GL_STATIC_DRAW );
    
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->EBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, this->m_indices.size( ) * sizeof( GLuint ), &this->m_indices[0], GL_STATIC_DRAW );
    
    // Set the vertex attribute pointers
    // Vertex Positions
    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )0 );
    // Vertex Normals
    glEnableVertexAttribArray( 1 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, m_normal ) );
    // Vertex Texture Coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, m_texCoords ) );
    
    glBindVertexArray( 0 );
}

