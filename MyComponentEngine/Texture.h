#pragma once
class Texture
{
private:
public:
	Texture(wstring path);

	LPD3DXSPRITE sprite;

	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 SetTexture(wstring path);

	D3DXIMAGE_INFO info;

	RECT imgRect;

	void Release();
};

