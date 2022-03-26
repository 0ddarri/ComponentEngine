#include "DXUT.h"
#include "Transform.h"
#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(wstring path)
{
	D3DXCreateSprite(DEVICE, &sprite);

	texture = SetTexture(path);
	SetRect(&imgRect, 0, 0, info.Width, info.Height);
}

LPDIRECT3DTEXTURE9 SpriteRenderer::SetTexture(wstring path)
{
	LPDIRECT3DTEXTURE9 tex = nullptr;

	auto isFail = D3DXCreateTextureFromFileEx(DEVICE, path.c_str(), -2, -2, 1, 0,
		D3DFORMAT::D3DFMT_A8B8G8R8, D3DPOOL::D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &info,
		nullptr, &tex);
	if (FAILED(isFail))
	{
		wcout << "SpriteRenderer Texture Load Fail : " << path.c_str() << endl;
		delete tex;
		return nullptr;
	}
	wcout << "SpriteRenderer Texture Load Success : " << path.c_str() << endl;
	return tex;
}

void SpriteRenderer::Update(float dt)
{
}

void SpriteRenderer::Render()
{
	sprite->Begin(NULL);

	D3DXMATRIX worldInv;

	DEVICE->SetTransform(D3DTS_WORLD, &transform->Matrix());
	DEVICE->SetTransform(D3DTS_VIEW, &Global::Instance()->main->camera->GetViewMatrix());
	DEVICE->SetTransform(D3DTS_PROJECTION, &Global::Instance()->main->camera->GetProjMatrix());
	D3DXVECTOR3 center(info.Width * 0.5f, info.Height * 0.5f, 0);
	sprite->Draw(texture, &imgRect, &center, nullptr, D3DXCOLOR(1, 1, 1, 1));
	sprite->End();
}

void SpriteRenderer::Release()
{
	sprite->Release();
	texture->Release();
}
