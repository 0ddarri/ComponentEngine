#pragma once
class GameObject;
class Transform;

class Component
{
private:
	GameObject* parent;
protected:
public:
	Component();
	Transform* transform;
	bool g_Enabled = true;
	GameObject* gameObject()
	{
		if (parent != nullptr) return parent;
		return nullptr;
	}
	void SetParent(GameObject* p);

	virtual void Initialize();

	virtual void Update();
	virtual void Render();
};

