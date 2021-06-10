#include "objects/Material.h"

namespace material = myproject::object;

void material::Material::SetShininess(float shininess)
{
    m_shininess = shininess;
}
float material::Material::GetShininess()
{
    return m_shininess;
}
vec3 material::Material::Get()
{
    vec3 v(m_shininess, 0.0f, 0.0f);
    return v;
}
