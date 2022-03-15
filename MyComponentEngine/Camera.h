#pragma once
#include "Component.h"

class Camera : public Component
{
private:
	D3DXVECTOR3 g_Look = { 0,0,0 };
	D3DXVECTOR3 g_Up = { 0,1,0 };
	D3DXVECTOR3 g_View = { 0,0,0 };
	D3DXVECTOR3 g_Cross = { 0,0,0 };

	D3DXMATRIXA16 g_viewMatrix;
	D3DXMATRIXA16 g_projMatrix;

	void SetView();

	void SetProj();
protected:
public:
	Camera();

	D3DXMATRIXA16 GetViewMatrix();
	D3DXMATRIXA16 GetProjMatrix();

	virtual void Update(float dt);

	virtual void Render();

	virtual void Release();

	void MoveLocalX(float speed);
	void MoveLocalY(float speed);
	void MoveLocalZ(float speed);
};

