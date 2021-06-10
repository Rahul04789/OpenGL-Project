#version 330 core
struct Material
{
    sampler2D m_diffuse;//sampler2D is a so called opaque type which means we can't instantiate these types, but only define them as uniforms.
                        //If the struct would be instantiated other than as a uniform (like a function parameter) GLSL could throw strange errors;
    sampler2D m_specular;
    float m_shininess;
};
struct Light
{
    vec3 m_position;
    vec3 m_direction;
    float m_cutOff;
    float m_outerCutOff;

    vec3 m_ambient;
    vec3 m_diffuse;
    vec3 m_specular;

    float m_constant;
    float m_linear;
    float m_quadratic;
};
out vec4 color;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3     viewPos;
uniform Material material;
uniform Light    light;

void main()
{
    // Ambient
    vec3 ambient = light.m_ambient * vec3(texture(material.m_diffuse, TexCoords));

    // Diffuse
    vec3 norm     = normalize(Normal);
    vec3 lightDir = normalize(light.m_position - FragPos);
    //vec3 lightDir = normalize(-light.m_direction);
    float diff    = max(dot(norm, lightDir), 0.0);
    vec3 diffuse  = light.m_diffuse * diff * vec3(texture(material.m_diffuse, TexCoords));

    // Specular
    vec3 viewDir    = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);//Note that we negate the lightDir vector. The reflect function expects the first vector to point from the light source towards the fragment's position, but the lightDir vector is currently pointing the other way around: from the fragment towards the light source
    float spec      = pow(max(dot(viewDir, reflectDir), 0.0), material.m_shininess);//This 32 value is the shininess value of the highlight
    vec3 specular   = light.m_specular * spec * vec3(texture(material.m_specular, TexCoords));

    // Spot Light
    float theta = dot(lightDir, normalize(-light.m_direction));
    float epsilon = (light.m_cutOff - light.m_outerCutOff);
    float intensity = clamp((theta - light.m_outerCutOff) / epsilon, 0.0, 1.0);

    diffuse *= intensity;
    specular *= intensity;
    
    // Attenuation
    float distance    = length(light.m_position - FragPos);
    float attenuation = 1.0f / (light.m_constant + light.m_linear * distance + light.m_quadratic * (distance * distance));

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0f);
}
