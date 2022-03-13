#include "DXUT.h"
#include "Transform.h"
#include "Camera.h"

Camera::Camera()
{
	D3DXVECTOR3 eyePos = { 0,0,0 };
	D3DXVECTOR3 Look = { 0.0f, 0.0f, -1.0f };
	D3DXVECTOR3 Up = { 0.0f,1.0f,0.0f };
	D3DXMatrixIdentity(&g_viewMatrix);
	D3DXMatrixIdentity(&g_projMatrix);

	D3DXMatrixLookAtLH(&g_viewMatrix, &eyePos, &Look, &Up);
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ºä¼³Á¤
}

void Camera::SetView()
{
	D3DXVECTOR3 eyePos = transform->position;
	g_Look = { 0.0f, eyePos.y, 0.0f };
	g_Up = { 0.0f,1.0f,0.0f };
	D3DXVec3Normalize(&g_View, &(g_Look - transform->position));
	D3DXVec3Cross(&g_Cross, &g_Up, &g_View);

	D3DXMatrixLookAtLH(&g_viewMatrix, &eyePos, &g_Look, &g_Up);
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ºä¼³Á¤
}

void Camera::SetProj()
{
	D3DXMatrixPerspectiveFovLH(&g_projMatrix, D3DX_PI / 4, 540.0f / 480.0f, 1.0f, 10000.0f);
	DEVICE->SetTransform(D3DTS_PROJECTION, &g_projMatrix); // Åõ¿µ¼³Á¤
}

void Camera::Update(float dt)
{
	if (DXUTIsKeyDown(VK_F1))
	{
		transform->position.x += 30 * dt;
	}
}

void Camera::Render()
{
	std::wcout << "asfd" << std::endl;
	SetView();
	SetProj();
}

void Camera::Release()
{
}
