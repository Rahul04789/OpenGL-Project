#include "Texture.h"
#include "SOIL2.h"
#include "Constants.h"

namespace texture = myproject::texture;

texture::Texture::Texture(std::string fileName, std::string texName):m_texName(texName)
{
    int width, height;
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    // Load, create texture and generate mipmaps
    unsigned char *image = SOIL_load_image(fileName.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}
void texture::Texture::Update(myproject::shader::Shader* pshader, std::string texName)
{
    if(texName.compare("diffuse")==0)
        glActiveTexture(GL_TEXTURE0);
    else if(texName.compare("specular")==0)
        glActiveTexture(GL_TEXTURE1);
    glBindTexture( GL_TEXTURE_2D, m_texture );
    //glUniform1i( glGetUniformLocation( pshader->GetShaderProgram(), "ourTexture" ), 0 );
}
