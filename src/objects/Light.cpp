#include "objects/Light.h"

namespace light = myproject::object;

void light::Light::SetPosition(vec3& position)
{
    m_position = position;
}
void light::Light::SetDirection(vec3& direction)
{
    m_direction = direction;
}
void light::Light::SetConstant(float constant)
{
    m_constant = constant;
}
void light::Light::SetLinear(float linear)
{
    m_linear = linear;
}
void light::Light::SetQuadratic(float quadratic)
{
    m_quadratic = quadratic;
}
vec3 light::Light::GetPosition()
{
    return m_position;
}
vec3 light::Light::GetDirection()
{
    return m_direction;
}
float light::Light::GetConstant()
{
    return m_linear;
}
float light::Light::GetLinear()
{
    return m_linear;
}
float light::Light::GetQuadratic()
{
    return m_quadratic;
}
vec3 light::Light::Get()
{
    return m_position;
}
