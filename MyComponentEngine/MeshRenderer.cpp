#include "DXUT.h"
#include "Component.h"
#include "Transform.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "Light.h"

MeshRenderer::MeshRenderer()
{
	mesh = SetMesh(L"Resources/Mesh/Teapot.x");
	shader = SetShader(L"Resources/Shader/NormalMapping.fx");

	material = new Material(L"albedo.tga", L"specular.jpg", L"normal.tga");
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

	D3DXMATRIXA16 worldViewMat;
	D3DXMatrixMultiply(&worldViewMat, &worldMatrix, &Global::Instance()->main->camera->GetViewMatrix());

	D3DXMATRIXA16 worldViewProjMatrix;
	D3DXMatrixMultiply(&worldViewProjMatrix, &worldViewMat, &Global::Instance()->main->camera->GetProjMatrix());

	D3DXMATRIXA16 worldInvMatrix;
	D3DXMatrixTranspose(&worldInvMatrix, &worldMatrix);

	shader->SetMatrix((D3DXHANDLE)"gWorldViewProjectionMatrix", &worldViewProjMatrix);
	shader->SetMatrix((D3DXHANDLE)"gWorldMatrix", &worldMatrix);
	//shader->SetMatrix((D3DXHANDLE)"gInvWorldMatrix", &worldInvMatrix);
	shader->SetMatrix((D3DXHANDLE)"gViewMatrix", &Global::Instance()->main->camera->GetViewMatrix());
	shader->SetMatrix((D3DXHANDLE)"gProjectionMatrix", &Global::Instance()->main->camera->GetProjMatrix());

	D3DXVECTOR4 campos(Global::Instance()->main->transform->position);
	shader->SetVector((D3DXHANDLE)"gWorldCameraPosition", &campos);
	D3DXVECTOR4 pos(transform->position);
	shader->SetVector((D3DXHANDLE)"worldPos", &pos);


	shader->SetTexture((D3DXHANDLE)"DiffuseMap", material->GetTexture(L"albedo"));
	shader->SetTexture((D3DXHANDLE)"SpecularMap", material->GetTexture(L"specular"));
	shader->SetTexture((D3DXHANDLE)"NormalMap", material->GetTexture(L"normal"));

	// light settings
	int i = 0;
	for (auto it : LightManager::Instance()->lightList)
	{
		cout << "num :" << i << endl;
		D3DXHANDLE light = shader->GetParameterElement((D3DXHANDLE)"lights", i);

		D3DXHANDLE hlightPos;
		D3DXHANDLE hlightColor;
		D3DXHANDLE hlightPower;

		hlightPos = shader->GetParameterByName(light, "WorldLightPos"); // 여기서 값전달해줘요
		hlightColor = shader->GetParameterByName(light, "LightColor");
		hlightPower = shader->GetParameterByName(light, "specularPower");

		D3DXVECTOR4 lightPos(it->transform->position);
		D3DXVECTOR4 lightColor(it->GetColor());

		shader->SetValue(hlightPos, &lightPos, sizeof(lightPos));
		shader->SetValue(hlightColor, &lightColor, sizeof(lightColor));
		shader->SetFloat(hlightPower, it->GetSpecularPower());

		//shader->SetVector((D3DXHANDLE)"gWorldLightPosition", &lightPos);
		//shader->SetVectorArray((D3DXHANDLE)"lights.WorldLightPos", &lightPos, i);
		//shader->SetVector((D3DXHANDLE)"gLightColor", &lightColor);
		//shader->SetFloat((D3DXHANDLE)"gSpecularPower", it->GetSpecularPower());
		i++;
	}
	MeshRender();
}

void MeshRenderer::MeshRender()
{
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

// 이거 로딩 원래 안됬던거임? 아뇨 원래는 잘됬는데 그 멀티라이팅 하다가 ㅈ댔어요
// 멀티 라이팅 코드를 쓰니 갑자기 로딩이 안됨? 코드가 맞는지도 모르겠어용ㅋㅋ 제가 직접 막한거라
// 미치겟네ㅋㅋ하핳하 색바꾸면 바뀌나 봐볼까용 ㄱㄱ 너가 하셈 나 곧 나가야해
// 넹 수고하셨어용
LPD3DXEFFECT MeshRenderer::SetShader(wstring path) // 쉐이더 로딩 자체가 안되용 뭔가 에러가나요
{
	LPD3DXEFFECT shader;
	LPD3DXBUFFER errormsg = nullptr;

	auto isFail = D3DXCreateEffectFromFile(DEVICE, path.c_str(), NULL, NULL, D3DXSHADER_DEBUG, NULL, &shader, &errormsg);
	if (FAILED(isFail))
	{
		wcout << "Shader Load Fail : " << path.c_str() << endl;
		MessageBox(DXUTGetHWND(), static_cast<WCHAR*>(errormsg->GetBufferPointer()), L"Shader Create Error", MB_OK);
		return nullptr;
	}
	wcout << "Shader Load : " << path.c_str() << endl;
	return shader;
}

void MeshRenderer::Release()
{
	mesh->Release();
	shader->Release();
	material->Release();
}
