#include "objects/Object.h"

namespace object = myproject::object;

void object::Object::SetAmbient(vec3 ambient)
{
    m_ambient = ambient;
}
void object::Object::SetDiffuse(vec3 diffuse)
{
    m_diffuse = diffuse;
}
void object::Object::SetSpecular(vec3 specular)
{
    m_specular = specular;
}
vec3 object::Object::GetAmbient()
{
    return m_ambient;
}
vec3 object::Object::GetDiffuse()
{
    return m_diffuse;
}
vec3 object::Object::GetSpecular()
{
    return m_specular;
}
