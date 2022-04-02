#include "DXUT.h"
#include "Global.h"

Global::Global()
{
	main = new MainCamera();
}

void Global::CreateSprite()
{
	D3DXCreateSprite(DEVICE, &sprite);
}

LPD3DXSPRITE Global::GetSprite()
{
	return sprite;
}

void Global::LostDevice()
{
	if (sprite == nullptr) return;
	sprite->OnLostDevice();
}

void Global::ResetDevice()
{
	if (sprite == nullptr) return;
	sprite->OnResetDevice();
}

void Global::Update(float dt)
{
	main->Update(dt);
}

void Global::Render()
{
	main->Render();
}

void Global::Release()
{
	sprite->Release();
}
