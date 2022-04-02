#include "DXUT.h"
#include "Texture.h"

Texture::Texture(wstring path)
{
	SetTexture(path);
	SetRect(&imgRect, 0, 0, info.Width, info.Height);
}

LPDIRECT3DTEXTURE9 Texture::SetTexture(wstring path)
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
	texture = tex;
	return tex;
}

void Texture::Release()
{
	texture->Release();
}
