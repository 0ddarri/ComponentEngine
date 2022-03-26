#pragma once
#include "Global.h"
#include "Component.h"

class SpriteRenderer : public Component
{
private:
protected:
public:
	SpriteRenderer(wstring path);

	LPD3DXSPRITE sprite;

	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 SetTexture(wstring path);

	D3DXIMAGE_INFO info;

	RECT imgRect;

	virtual void Update(float dt);
	virtual void Render();

	virtual void Release();
};

