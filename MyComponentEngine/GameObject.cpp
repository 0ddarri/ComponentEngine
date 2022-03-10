#include "DXUT.h"
#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::~GameObject()
{
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
