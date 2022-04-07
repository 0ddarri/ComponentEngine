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
	parent = p;
	transform = p->transform;
}

void Component::Update(float dt)
{
}

void Component::Render()
{
}

void Component::ResetDevice()
{
}

void Component::LostDevice()
{
}
