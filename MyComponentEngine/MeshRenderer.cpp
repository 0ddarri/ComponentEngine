#include "DXUT.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	mesh = SetMesh(L"Resources/Mesh/Teapot.x");
	shader = SetShader(L"Resources/Shader/ColorShader.fx");
}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::Update()
{
}

void MeshRenderer::Render()
{
	D3DXMATRIXA16 worldviewprojMatrix;

	shader->SetMatrix((D3DXHANDLE)"gWorldViewProjectionMatrix", &worldviewprojMatrix);
	
	UINT passnum;
	shader->Begin(&passnum, NULL);
	for (UINT i = 0; i < passnum; i++)
	{
		shader->BeginPass(i);
		mesh->DrawSubset(0);
		shader->EndPass();
	}
	shader->End();
}

LPD3DXMESH MeshRenderer::SetMesh(wstring path)
{
	LPD3DXMESH mesh;
	auto isFail = D3DXLoadMeshFromX(path.c_str(), D3DXMESH_SYSTEMMEM, DEVICE, nullptr, nullptr, nullptr, nullptr, &mesh);
	if (FAILED(isFail))
	{
		wcout << "Mesh Load Fail : " << path << std::endl;
		return nullptr;
	}
	wcout << "Mesh Load : " << path << std::endl;
	return mesh;
}

LPD3DXEFFECT MeshRenderer::SetShader(wstring path)
{
	LPD3DXEFFECT shader;
	auto isFail = D3DXCreateEffectFromFile(DEVICE, path.c_str(), NULL, NULL, D3DXSHADER_DEBUG, NULL, &shader, NULL);
	if (FAILED(isFail))
	{
		wcout << "Shader Load Fail : " << path.c_str() << endl;
		return nullptr;
	}
	wcout << "Shader Load : " << path.c_str() << endl;
	return shader;
}
