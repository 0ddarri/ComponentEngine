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

	void ResetDevice();
	void LostDevice();

	virtual void Release();
};
