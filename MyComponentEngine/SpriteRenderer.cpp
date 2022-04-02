#include "DXUT.h"
#include "Transform.h"
#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(wstring path)
{
	texture = new Texture(path);
}

void SpriteRenderer::Update(float dt)
{
}

void SpriteRenderer::Render()
{
	Global::Instance()->GetSprite()->Begin(NULL);

	D3DXMATRIX worldInv;

	DEVICE->SetTransform(D3DTS_WORLD, &transform->Matrix());
	DEVICE->SetTransform(D3DTS_VIEW, &Global::Instance()->main->camera->GetViewMatrix());
	DEVICE->SetTransform(D3DTS_PROJECTION, &Global::Instance()->main->camera->GetProjMatrix());
	D3DXVECTOR3 center(texture->info.Width * 0.5f, texture->info.Height * 0.5f, 0);
	Global::Instance()->GetSprite()->Draw(texture->texture, &texture->imgRect, &center, nullptr, D3DXCOLOR(1, 1, 1, 1));
	Global::Instance()->GetSprite()->End();
}

void SpriteRenderer::Release()
{
	texture->Release();
}
