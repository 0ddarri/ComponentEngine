#pragma once
#include "GameObject.h"

class Scene
{
private:
protected:
public:
	Scene() {};
	Scene(wstring name);
	list<GameObject*> hierarchy;
	wstring name;

	virtual void Start();
	virtual void Update(float dt);
	virtual void Render();

	virtual void Release();
};

