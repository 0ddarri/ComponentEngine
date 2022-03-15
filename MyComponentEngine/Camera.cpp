#include "DXUT.h"
#include "Transform.h"
#include "Camera.h"

Camera::Camera()
{
	D3DXVECTOR3 eyePos = { 0,0,0 };
	D3DXVECTOR3 Look = { 0.0f, 0.0f, 0.0f };
	D3DXVECTOR3 Up = { 0.0f,1.0f,0.0f };
	D3DXMatrixIdentity(&g_viewMatrix);
	D3DXMatrixIdentity(&g_projMatrix);

	D3DXMatrixLookAtLH(&g_viewMatrix, &eyePos, &Look, &Up);
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ºä¼³Á¤
}

D3DXMATRIXA16 Camera::GetViewMatrix()
{
	return g_viewMatrix;
}

D3DXMATRIXA16 Camera::GetProjMatrix()
{
	return g_projMatrix;
}

void Camera::SetView()
{
	D3DXVECTOR3 eyePos = transform->position;
	D3DXVECTOR3 look = g_Look;
	D3DXVECTOR3 up = g_Up;
	D3DXVec3Normalize(&g_View, &(look - transform->position));
	D3DXVec3Cross(&g_Cross, &up, &g_View);

	D3DXMatrixLookAtLH(&g_viewMatrix, &eyePos, &look, &up);
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ºä¼³Á¤
}

void Camera::SetProj()
{
	D3DXMatrixPerspectiveFovLH(&g_projMatrix, D3DX_PI / 4, 540.0f / 480.0f, 1.0f, 10000.0f);
	DEVICE->SetTransform(D3DTS_PROJECTION, &g_projMatrix); // Åõ¿µ¼³Á¤
}

void Camera::Update(float dt)
{
	if (DXUTIsKeyDown(VK_F1)) MoveLocalZ(-200 * dt);
	if (DXUTIsKeyDown(VK_F2)) MoveLocalY(-200 * dt);
	if (DXUTIsKeyDown(VK_F3)) MoveLocalX(-200 * dt);
}

void Camera::Render()
{
	SetView();
	SetProj();
}

void Camera::Release()
{
}

void Camera::MoveLocalX(float speed)
{
	D3DXVECTOR3 vMove;
	D3DXVec3Normalize(&vMove, &g_Cross);
	vMove *= speed;
	transform->position += vMove;
	g_Look += vMove;
}

void Camera::MoveLocalY(float speed)
{
	D3DXVECTOR3 vMove;
	D3DXVec3Normalize(&vMove, &g_Up);
	vMove *= speed;
	transform->position += vMove;
	g_Look += vMove;
}

void Camera::MoveLocalZ(float speed)
{
	D3DXVECTOR3 vMove = g_View;
	vMove *= speed;
	transform->position += vMove;
	g_Look += vMove;
}
