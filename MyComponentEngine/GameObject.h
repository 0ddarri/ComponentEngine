#pragma once
#include "Component.h"

class GameObject
{
private:
	bool g_isActive = true;
	vector<Component*> g_inspector;
protected:
public:
	GameObject();
	~GameObject();

	Transform* transform;

	//template <typename T>
	//T& AddComponent()
	//{
	//	T* comp = new T();
	//	Component* component = new Component();
	//	component = static_cast<Component*>(comp);
	//	component->SetParent(this);
	//	component->Initialize();
	//	g_inspector.push_back(component);
	//	return *static_cast<T*>(comp);
	//}

	Component* AddComponent(Component* comp);
	Component* GetComponent(Component* comp);

	//template <typename T>
	//T& GetComponent()
	//{
	//	for (Component* comp : g_inspector)
	//	{
	//		if (dynamic_cast<T*>(comp) != nullptr)
	//			return *static_cast<T*>(comp);
	//	}
	//}

	virtual void Update(float dt)
	{
		for (Component* component : g_inspector)
		{
			if (component->g_Enabled)
			{
				component->Update(dt);
			}
		}
	}
	virtual void Render()
	{
		for (Component* component : g_inspector)
		{
			if (component->g_Enabled)
			{
				component->Render();
			}
		}
	}

	virtual void Release();
};
