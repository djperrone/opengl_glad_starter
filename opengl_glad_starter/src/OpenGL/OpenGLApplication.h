#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class OpenGLApplication
{
public:
	OpenGLApplication();
	void Run();	
	void HandleInput();
	void Render();	

	void InitGLFW();
	void ProcessInput();

private:
	GLFWwindow* m_Window;
};