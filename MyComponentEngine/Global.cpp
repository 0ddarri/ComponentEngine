#include "DXUT.h"
#include "Global.h"

Global::Global()
{
	main = new MainCamera();
}

void Global::Update(float dt)
{
	main->Update(dt);
}

void Global::Render()
{
	main->Render();
}
