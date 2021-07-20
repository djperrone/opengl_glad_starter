#pragma once

class Application
{
public:
	virtual ~Application() = default;
	virtual void Run() = 0;
	//virtual void PollEvents() = 0;
	virtual void HandleInput() = 0;
	virtual void Render() = 0;
};