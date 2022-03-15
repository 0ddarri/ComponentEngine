#pragma once
#include "Singleton.h"
#include "Camera.h"
#include "GameObject.h"

static class MainCamera : public GameObject
{
private:

protected:
public:
	MainCamera();

	Camera* camera;

	virtual void Update(float dt);

	virtual void Render();

	virtual void Release();
};

