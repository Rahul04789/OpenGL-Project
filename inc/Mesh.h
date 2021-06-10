#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Shader_old.h"
#include "Projection.h"

namespace myproject
{
    namespace vertex
    {
        class Vertex
        {
        public:
            Vertex(const glm::vec3& pos):m_pos{pos}{}
        private:
            glm::vec3 m_pos;
        };
    }
    namespace mesh
    {
        enum VAO //these are for different objects 
        {
            LIGHTING_VAO,
            NUM_BUFFERS,
            LAPM_VAO,
            LINE_VAO
        };
        class Mesh
        {
        public:
            Mesh(const GLfloat *vertices, const unsigned int& vertecessize);
            virtual ~Mesh();
            void DrawLight(myproject::projection::Projection* projection, myproject::shader::Shader* shader);//this func. will take our mesh and draw it. It will send mesh into the pipeline to produce into  afinal image.
            void DrawLamp (myproject::projection::Projection* projection, myproject::shader::Shader* shader);
            void DrawLine(myproject::projection::Projection* projection, myproject::shader::Shader* shader);
        private:
            Mesh(const Mesh& rhs){}
            void operator=(const Mesh& rhs){}

            /*GLuint: this is how opengl refers to all its data on the gpu.*/
            GLuint m_vertexArrayObject[NUM_BUFFERS];// modern opengl way for referring to mesh data on gpu
            GLuint m_vertexArrayBuffers;
            unsigned int m_drawCount;//count of how many vertices we are trying to draw.(how many of m_vertexArrayObject we want to draw).
            //GLuint EBO;//element buffer object
        };
    }
}

#endif
