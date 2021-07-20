#include "OpenGLApplication.h"

#include <iostream>

OpenGLApplication::OpenGLApplication()
{
    InitGLFW();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void OpenGLApplication::Run()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        HandleInput();
        Render();        
    }

    glfwTerminate();
}

void OpenGLApplication::HandleInput()
{
    glfwPollEvents();
    ProcessInput();
}

void OpenGLApplication::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(m_Window);
}

void OpenGLApplication::InitGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_Window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
      
        exit(0);
    }
    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;     
        exit(0);
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        
        });
    
    std::cout << glGetString(GL_VERSION) << std::endl;
}

void OpenGLApplication::ProcessInput()
{
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}
