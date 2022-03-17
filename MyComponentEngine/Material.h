#pragma once
class Material
{
private:
	map<wstring, LPDIRECT3DTEXTURE9> texturelist;

	LPDIRECT3DTEXTURE9 defaultTexture;

protected:
public:
	Material(wstring albedo, wstring specular, wstring normal);

	LPDIRECT3DTEXTURE9 GetTexture(wstring name);

	LPDIRECT3DTEXTURE9 LoadTexture(wstring path, wstring name);

	void Release();
};

