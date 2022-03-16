#include "DXUT.h"
#include "MainCamera.h"
#include "Transform.h"

MainCamera::MainCamera()
{
	std::wcout << "五昔朝五虞 持失切" << std::endl;
	camera = new Camera();
	transform->position = { -200,0,0 };
	camera->SetParent(this);
}

void MainCamera::Update(float dt)
{
	camera->Update(dt);
}

void MainCamera::Render()
{
	camera->Render();
}

void MainCamera::Release()
{
	camera->Release();
}
