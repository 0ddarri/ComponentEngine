#include "DXUT.h"
#include "Scene.h"

Scene::Scene(wstring name)
{
	this->name = name;
	cout << "ȣ" << endl;
}

void Scene::Start()
{
	cout << "��" << endl;
}

void Scene::Update(float dt)
{
	for (auto it : hierarchy)
	{
		it->Update(dt);
	}
}

void Scene::Render()
{
	for (auto it : hierarchy)
	{
		it->Render();
	}
}

void Scene::Release()
{
	for (auto it : hierarchy)
	{
		it->Release();
	}
}
