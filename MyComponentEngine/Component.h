#pragma once

class Component
{
private:
protected:
public:
	Component();

	bool g_Enabled = true;

	virtual void Initialize();

	virtual void Update();
	virtual void Render();
};

