#pragma once
#include"Global.h"

class MeshRenderer : public Component
{
private:
	LPD3DXEFFECT shader;
	LPD3DXMESH mesh;
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

