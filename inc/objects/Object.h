#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>

using namespace glm;

namespace myproject
{
    namespace object
    {
        class Object
        {
            vec3 m_ambient;
            vec3 m_diffuse;
            vec3 m_specular;
        public:
            void SetAmbient(vec3 ambient);
            void SetDiffuse(vec3 diffuse);
            void SetSpecular(vec3 specular);
            vec3 GetAmbient();
            vec3 GetDiffuse();
            vec3 GetSpecular();
            
            virtual vec3 Get() = 0;
        };
    }
}

#endif
