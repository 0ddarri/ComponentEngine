#include "DXUT.h"
#include "Material.h"

Material::Material(wstring albedo, wstring specular, wstring normal)
{
	defaultTexture = LoadTexture(L"Resources/Textures/defaultTexture.jpg", L"defaultTexture");

	wstring albedoPath = L"Resources/Textures/" + albedo;
	LPDIRECT3DTEXTURE9 albedoTexture = LoadTexture(albedoPath, L"albedo");
	wstring specularPath = L"Resources/Textures/" + specular;
	LPDIRECT3DTEXTURE9 specularTexture = LoadTexture(specularPath, L"specular");
	wstring normalPath = L"Resources/Textures/" + normal;
	LPDIRECT3DTEXTURE9 normalTexture = LoadTexture(normalPath, L"normal");
}

LPDIRECT3DTEXTURE9 Material::GetTexture(wstring name)
{
	auto texture = texturelist.find(name);
	if (texture != texturelist.end())
	{
		return texture->second;
	}
	return nullptr;
}

LPDIRECT3DTEXTURE9 Material::LoadTexture(wstring path, wstring name)
{
	LPDIRECT3DTEXTURE9 texture;

	auto isFail = D3DXCreateTextureFromFile(DEVICE, path.c_str(), &texture);
	if (FAILED(isFail))
	{
		wcout << "Texture Load Fail : " << path.c_str() << endl;
		delete texture;
		return defaultTexture;
	}
	wcout << "Texture Load : " << path.c_str() << endl;
	texturelist.emplace(name, texture);
	return texture;
}

void Material::Release()
{
	for (auto texture : texturelist)
	{
		texture.second->Release();
	}
}
