#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"

namespace myproject
{
    namespace object
    {
        //namespace light
        //{
            class Light: public Object
            {
                vec3 m_position;
                vec3 m_direction;
                float m_constant;
                float m_linear;
                float m_quadratic;
            public:
                void SetPosition(vec3& position);
                void SetDirection(vec3& direction);
                void SetConstant(float constant);
                void SetLinear(float linear);
                void SetQuadratic(float quadratic);
                vec3 GetPosition();
                vec3 GetDirection();
                float GetConstant();
                float GetLinear();
                float GetQuadratic();
                virtual vec3 Get() override;
            };
        //}
    }
}

#endif
