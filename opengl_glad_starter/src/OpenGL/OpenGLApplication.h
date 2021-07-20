#pragma once
#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class OpenGLApplication : public Application
{
public:
	OpenGLApplication();
	virtual void Run() override;	
	virtual void HandleInput() override;
	virtual void Render() override;	

	void InitGLFW();
	void ProcessInput();
	


private:
	GLFWwindow* m_Window;
};