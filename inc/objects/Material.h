#ifndef MATERIAL_H
#define MATERIAL_H

#include "Object.h"

namespace myproject
{
    namespace object
    {
        //namespace material
        //{
            class Material: public Object
            {
                float m_shininess;
            public:
                void SetShininess(float shininess);
                float GetShininess();
                virtual vec3 Get() override;
            };
        //}
    }
}

#endif
