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

	virtual void Update(float dt);
	virtual void Render();

	virtual void Release() PURE;

	virtual void ResetDevice();
	virtual void LostDevice();
};

