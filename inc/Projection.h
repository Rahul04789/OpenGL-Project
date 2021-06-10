#ifndef PROJECTION_H
#define PROJECTION_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
namespace myproject{namespace projection{class Projection;}}
#include "Shader_old.h"
#include "Window.h"
#include "Camera.h"

namespace myproject
{
    namespace projection
    {
        enum PROJECTION_TYPE
        {
            PROJECTION_NONE,
            PROJECTION_ORTHOGRAPHIC,
            PROJECTION_PERSPECTIVE
        };
        class Projection
        {
        public:
            Projection (PROJECTION_TYPE projectionType = PROJECTION_NONE)
            :m_projectionType(projectionType)
            {}

            inline glm::mat4& GetProjection() {return m_projection;}
            inline glm::mat4& GetModel()      {return m_model;}
            inline glm::mat4& GetView()       {return m_view;}

            inline void SetProjection(const glm::mat4& proj) {m_projection = proj;}
            inline void SetModel(const glm::mat4& model)     {m_model = model;}
            inline void SetView(const glm::mat4& view)       {m_view = view;}

            void SetProjectionType(PROJECTION_TYPE projtype);
            void SetProjection(myproject::window::Window* window, myproject::camera::Camera* camera);

            void UpdateView(myproject::shader::Shader* pshader);
            void UpdateModel(myproject::shader::Shader* pshader);
            void UpdateProjection(myproject::shader::Shader* pshader);
        private:
            Projection(const Projection& rhs){}
            void operator=(Projection& rhs){}

            PROJECTION_TYPE m_projectionType;
            glm::mat4       m_projection;
            glm::mat4       m_model;
            glm::mat4       m_view;
        };
    }
}

#endif
