#include "DXUT.h"
#include "Transform.h"
#include "Image.h"

Image::Image(wstring path)
{
	texture = new Texture(path);
}

void Image::Update(float dt)
{
	
}

void Image::Render()
{
	Global::Instance()->GetSprite()->Begin(NULL);

	D3DXMATRIXA16 worldMatrix = transform->Matrix();
	DEVICE->SetTransform(D3DTS_WORLD, &worldMatrix);

	D3DXMATRIXA16 viewMatrix = Global::Instance()->main->camera->GetViewMatrix();
	D3DXMATRIXA16 projMatrix = Global::Instance()->main->camera->GetProjMatrix();

	D3DXMATRIXA16 WVP = worldMatrix * viewMatrix * projMatrix;

	D3DXVECTOR4 worldToScreen(0, 0, 0, 1);
	D3DXVec4Transform(&worldToScreen, &worldToScreen, &WVP);
	
	float worldToScreenX = worldToScreen.x / worldToScreen.w;
	float worldToScreenY = worldToScreen.y / worldToScreen.w;
	float worldToScreenZ = worldToScreen.z / worldToScreen.w;

	float ScreenNormalX = (worldToScreenX + 1) * 0.5f;
	float ScreenNormalY = (worldToScreenY + 1) * 0.5f;
	ScreenNormalY = 1.0f - ScreenNormalY;

	float screenX = ScreenNormalX * SCW;
	float screenY = ScreenNormalY * SCH;

	D3DXVECTOR3 center(texture->info.Width * 0.5f, texture->info.Height * 0.5f, 0);
	Global::Instance()->GetSprite()->Draw(texture->texture, &texture->imgRect, &center, nullptr, D3DXCOLOR(1, 1, 1, 1));
	Global::Instance()->GetSprite()->End();
}

void Image::Release()
{
	texture->Release();
}
