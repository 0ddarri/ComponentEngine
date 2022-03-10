#pragma once
#include "Component.h"
#include "Transform.h"

class GameObject
{
private:
	bool g_isActive = true;
	Transform* transform;
	vector<Component*> g_inspector;
protected:
public:
	GameObject();
	~GameObject();
	


	template <typename T>
	T& AddComponent()
	{
		T* comp = new T();
		Component* component = static_cast<Component*>(comp);
		component->Initialize();
		g_inspector.emplace_back(component);
		return *static_cast<T*>(comp);
	}

	template <typename T>
	T& GetComponent()
	{
		for (Component* comp : g_inspector)
		{
			if (dynamic_cast<T*>(comp) != nullptr)
				return *static_cast<T*>(comp);
		}
	}

	virtual void Update()
	{
		for (Component* component : g_inspector)
		{
			component->Update();
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
};
