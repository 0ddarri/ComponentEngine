#include "DXUT.h"
#include "Component.h"
#include "Transform.h"
#include "Camera.h"
#include "MainCamera.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer()
{
	mesh = SetMesh(L"Resources/Mesh/Teapot.x");
	shader = SetShader(L"Resources/Shader/ColorShader.fx");
}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::Update(float dt)
{
}

void MeshRenderer::Render()
{
	D3DXMATRIXA16 worldMatrix = transform->Matrix();
	DEVICE->SetTransform(D3DTS_WORLD, &worldMatrix); // 월드 설정

	//D3DXVECTOR3 vEyePt(0, 0, -200.0f);
	//D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	//D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	//D3DXMATRIXA16 matView;
	//D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	//DEVICE->SetTransform(D3DTS_VIEW, &matView); // 뷰설정

	//D3DXMATRIXA16 matProj;
	//D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 540.0f/480.0f, 1.0f, 10000.0f);
	//DEVICE->SetTransform(D3DTS_PROJECTION, &matProj); // 투영설정

	// 쉐이더 설정
	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &worldMatrix);
	shader->SetMatrix((D3DXHANDLE)"gViewMatrix", &MainCamera::camera->GetViewMatrix());
	//shader->SetMatrix((D3DXHANDLE)"gProjectionMatrix", &matProj);
	
	UINT passnum;
	shader->Begin(&passnum, NULL);
	for (UINT i = 0; i < passnum; i++)
	{
		shader->BeginPass(i);
		mesh->DrawSubset(0); // 렌더링
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

void MeshRenderer::Release()
{
	mesh->Release();
	shader->Release();
}
