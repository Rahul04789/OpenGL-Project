#ifndef MESHASSIMP_H
#define MESHASSIMP_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader_old.h"
#include <assimp/types.h>

namespace myproject
{
    namespace meshassimp
    {
        struct Vertex
        {
            glm::vec3 m_position;
            glm::vec3 m_normal;
            glm::vec2 m_texCoords;
        };
        struct Texture
        {
            GLuint      m_id;
            std::string m_type;
            aiString m_path;
        };
        class Mesh
        {
        public:
            std::vector<Vertex>  m_vertices;
            std::vector<GLuint>  m_indices;
            std::vector<Texture> m_textures;

            Mesh(std::vector<Vertex>  vertices,
                 std::vector<GLuint>  indices,
                 std::vector<Texture> textures);
            void Draw(myproject::shader::Shader* shader);
        private:
            GLuint VAO, VBO, EBO;
            void SetUpMesh();
        };
    }
}

#endif
