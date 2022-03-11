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
	component->Initialize();
	g_inspector.push_back(component);
	std::cout << g_inspector.size() << std::endl;
	return component;
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
