#pragma once
#include"Global.h"
#include"Material.h"

class MeshRenderer : public Component
{
private:
	LPD3DXEFFECT shader;
	LPD3DXMESH mesh;

	Material* material;
protected:
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Update(float dt);
	virtual void Render();

	LPD3DXMESH SetMesh(wstring path);
	LPD3DXEFFECT SetShader(wstring path);

	virtual void Release();
};

