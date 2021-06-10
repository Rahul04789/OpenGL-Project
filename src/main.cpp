#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader_old.h"
#include "Window.h"
#include "Constants.h"
#include "Mesh.h"
#include "Projection.h"
#include "KeyListener.h"
#include "MouseListener.h"
#include "ScrollListener.h"
#include "Camera.h"
#include "objects/Light.h"
#include "objects/Material.h"
#include "ConstantsObject.h"
#include "Texture.h"
#include "Model.h"

glm::vec3 LIGHTPOS(0.0f, -1.75f, 0.0f);//1.2f, 1.0f, 2.0f );
//glm::vec3 LIGHTDIR(-0.2f, -1.0f, -0.3f);

int main()
{
    myproject::window::Window window(myproject::window::WIDTH, myproject::window::HEIGHT, myproject::window::TITLE.c_str());
    myproject::camera::Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
    myproject::keylistener::KeyListener::GetInstance(&window)->Initialize();
    myproject::mouselistener::MouseListener::m_camera = &camera;
    myproject::mouselistener::MouseListener::GetInstance(&window)->Initialize();
    myproject::scrolllistener::ScrollListener::m_camera = &camera;
    myproject::scrolllistener::ScrollListener::GetInstance(&window)->Initialize();
    
    glEnable(GL_DEPTH_TEST);//to enable the depth
    //glEnable(GL_BLEND);   //enable alpha support for images like .png
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Options, removes the mouse cursor for a more immersive experience
    glfwSetInputMode(window.GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //myproject::shader::Shader         lightingShader(myproject::shader::SHADER1.c_str(), "lighting");
    //myproject::shader::Shader         lampShader    (myproject::shader::SHADER2.c_str(), "lamp");
    //myproject::shader::Shader         lineShader    (myproject::shader::SHADER3.c_str(), "line");
    myproject::shader::Shader         modelShader    (myproject::shader::SHADER4.c_str(), "modelcharactor");
    Model ourModel1((GLchar*)myproject::model::MODEL1.c_str());
    Model ourModel2((GLchar*)myproject::model::MODEL2.c_str());
    //myproject::mesh::Mesh             mesh(myproject::vertices::vertices, myproject::vertices::vertecessize);
    myproject::projection::Projection projection;
    //myproject::texture::Texture       diffuseTexture (myproject::image::IMAGE5, "diffuse");
    //myproject::texture::Texture       specularTexture(myproject::image::IMAGE6, "specular");

    projection.SetProjectionType(myproject::projection::PROJECTION_PERSPECTIVE);
    projection.SetProjection(&window, &camera);

    /*
    myproject::object::Light    lightSource;
    myproject::object::Material material;

    lightSource.SetPosition(LIGHTPOS);
    //lightSource.SetDirection(LIGHTDIR);
    lightSource.Object::SetSpecular(vec3(1.0f, 1.0f, 1.0f));
    lightSource.Object::SetDiffuse(vec3(0.8f, 0.8f, 0.8f));
    lightSource.Object::SetAmbient(vec3(0.1f, 0.1f, 0.1f)); 
    lightSource.SetConstant(1.0f);
    lightSource.SetLinear(0.09f);
    lightSource.SetQuadratic(0.032f);

    //material.Object::SetAmbient(vec3(1.0f, 0.5f, 0.31f));
    //material.Object::SetDiffuse(vec3(1.0f, 0.5f, 0.31f));
    //material.Object::SetSpecular(vec3(0.5f, 0.5f, 0.5f));
    material.SetShininess(32.0f);

    std::vector<myproject::object::Object*> objects;
    objects.push_back(&lightSource);
    objects.push_back(&material);
    myproject::object::ObjectContainer objContainer(objects, 1, 1);
    */
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    //float f=0.0f;
    while(!window.IsClosed())
    {
        // LIGHTPOS.x += cosf(f)/100;
        // LIGHTPOS.z += sinf(f)/100;
        // LIGHTPOS.y += cosf(f)/100;
        // f+=0.01f;
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        camera.DoMovement(deltaTime);
        projection.SetView(camera.GetViewMatrix());

        window.Clear(0.1f, 0.1f, 0.1f, 1.0f);

        //lightSource.SetPosition(camera.GetPosition());//LIGHTPOS);
        // Set lights properties
        //lightSource.SetPosition(LIGHTPOS);
        /*glm::vec3 lightColor;
        lightColor.r = sin(glfwGetTime() * 2.0f);
        lightColor.g = sin(glfwGetTime() * 0.7f);
        lightColor.b = sin(glfwGetTime() * 1.3f);
        glm::vec3 diffuseColor = glm::vec3(0.5f, 0.5f, 0.5f);//lightColor * glm::vec3( 0.5f ); // Decrease the influence
        glm::vec3 ambientColor = glm::vec3(0.2f, 0.2f, 0.2f);//diffuseColor * glm::vec3( 0.2f ); // Low influence
        lightSource.Object::SetDiffuse(diffuseColor);
        lightSource.Object::SetAmbient(ambientColor);*/

        /*
        lightingShader.Bind();
        lightingShader.UpdateFragmentShader(myproject::fragmentshader_uniform_variables::FS_UV, &camera, objContainer);
        lightingShader.UpdateVertexShader(myproject::vertexshader_uniform_variables::VS_UV, &projection, LIGHTPOS);
        mesh.DrawLight(&projection, &lightingShader);

        diffuseTexture. Update(nullptr, "diffuse");
        specularTexture.Update(nullptr, "specular");
        */
        /*lampShader.Bind();
        lampShader.UpdateVertexShader(myproject::vertexshader_uniform_variables::VS_UV, &projection, LIGHTPOS);
        mesh.DrawLamp(&projection, &lampShader);*/

        /*lineShader.Bind();
        lineShader.UpdateVertexShader(myproject::vertexshader_uniform_variables::VS_UV, &projection, LIGHTPOS);
        mesh.DrawLine(&projection, &lineShader);*/
        
        modelShader.Bind();
        modelShader.UpdateVertexShader(myproject::vertexshader_uniform_variables::VS_UV, &projection, LIGHTPOS);
        ourModel2.Draw(&modelShader);


        window.Update();
    }    
    return EXIT_SUCCESS;
}

