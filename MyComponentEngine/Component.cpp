#include "DXUT.h"
#include "Component.h"
#include "Transform.h"
#include "GameObject.h"

Component::Component()
{
	g_Enabled = true;
}


void Component::SetParent(GameObject* p)
{
	parent = new GameObject();
	parent = p;
	transform = p->transform;
}

void Component::Update(float dt)
{
}

void Component::Render()
{
}
