#pragma once
#include "Singleton.h"
#include "MainCamera.h"

class Global : public Singleton<Global>
{
private:
public:
	Global();

	MainCamera* main;

	void Update(float dt);

	void Render();
};

