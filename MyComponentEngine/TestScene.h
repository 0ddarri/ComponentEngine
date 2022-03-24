#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Light.h"
#include "Transform.h"
#include "MeshRenderer.h"

class TestScene : public Scene
{
private:
protected:
public:
	GameObject* testObject;
	GameObject* testLight1;
	GameObject* testLight2;

	TestScene(wstring n);
	virtual void Start();
	virtual void Update(float dt);
	virtual void Render();
	virtual void Release();
};

