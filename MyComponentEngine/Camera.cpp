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
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ∫‰º≥¡§
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
	DEVICE->SetTransform(D3DTS_VIEW, &g_viewMatrix); // ∫‰º≥¡§
}

void Camera::SetProj()
{
	D3DXMatrixPerspectiveFovLH(&g_projMatrix, D3DX_PI / 4, 540.0f / 480.0f, 1.0f, 10000.0f);
	DEVICE->SetTransform(D3DTS_PROJECTION, &g_projMatrix); // ≈ıøµº≥¡§
}

void Camera::Update(float dt)
{
	if (DXUTIsKeyDown('W')) MoveLocalZ(200 * dt);
	if (DXUTIsKeyDown('S')) MoveLocalZ(-200 * dt);
	if (DXUTIsKeyDown('E')) MoveLocalY(200 * dt);
	if (DXUTIsKeyDown('Q')) MoveLocalY(-200 * dt);
	if (DXUTIsKeyDown('A')) MoveLocalX(-200 * dt);
	if (DXUTIsKeyDown('D')) MoveLocalX(200 * dt);
	if (DXUTIsKeyDown(VK_F4)) RotateLocalX(-1 * dt);
	if (DXUTIsKeyDown(VK_F5)) RotateLocalY(-1 * dt);
	if (DXUTIsKeyDown(VK_F6)) RotateLocalZ(-1 * dt);
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

void Camera::RotateLocalX(float angle)
{
	D3DXMATRIXA16 rotMatrix;
	D3DXMatrixRotationAxis(&rotMatrix, &g_Cross, angle);

	D3DXVec3TransformCoord(&g_Look, &g_View, &rotMatrix);
	g_Look += transform->position;
}

void Camera::RotateLocalY(float angle)
{
	D3DXMATRIXA16 rotMatrix;
	D3DXMatrixRotationAxis(&rotMatrix, &g_Up, angle);

	D3DXVec3TransformCoord(&g_Look, &g_View, &rotMatrix);
	g_Look += transform->position;
}

void Camera::RotateLocalZ(float angle) // æÍ π∫∞° ¿ÃªÛ«‘§ª§ª
{
	D3DXMATRIXA16 rotMatrix;
	D3DXMatrixRotationAxis(&rotMatrix, &g_View, angle);

	D3DXVec3TransformCoord(&g_Cross, &g_Cross, &rotMatrix);
	D3DXVec3TransformCoord(&g_Up, &g_Up, &rotMatrix);
}
