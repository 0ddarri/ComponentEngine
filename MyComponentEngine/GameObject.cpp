#include "DXUT.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "MeshRenderer.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::~GameObject()
{
}

Component* GameObject::AddComponent(Component* comp)
{
	Component* component = comp;
	component->SetParent(this);
	g_inspector.push_back(component);
	std::cout << g_inspector.size() << std::endl;
	return component;
}

Component* GameObject::GetComponent(Component* comp)
{
	for (Component* it : g_inspector)
	{
		if (it == comp)
		{
			std::wcout << "Find Component" << std::endl;
			return it;
		}
	}
	return nullptr;
}

void GameObject::Release()
{
	for (auto& it : g_inspector)
	{
		it->Release();
	}
}

//Component* GameObject::AddComponent(Component* component)
//{
//	Component* comp = new Component(component);
//	comp->Initialize();
//	g_inspector.push_back(comp);
//	return comp;
//}
//
//Component* GameObject::GetComponent(Component* component)
//{
//	for (Component* comp : g_inspector)
//	{
//		if (comp == component) return comp;
//	}
//	return nullptr;
//}
