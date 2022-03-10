#pragma once
#include "Component.h"

class MeshRenderer : public Component
{
private:
	LPD3DXEFFECT shader;
	LPD3DXMESH mesh;
protected:
public:
	MeshRenderer();
	virtual ~MeshRenderer();

	virtual void Update();
	virtual void Render();

	LPD3DXMESH SetMesh(wstring path);
	LPD3DXEFFECT SetShader(wstring path);
};

