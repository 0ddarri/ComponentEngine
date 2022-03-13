#pragma once
#include "Component.h"

class Camera : public Component
{
private:
	D3DXVECTOR3 g_Look;
	D3DXVECTOR3 g_Up;
	D3DXVECTOR3 g_View;
	D3DXVECTOR3 g_Cross;

	D3DXMATRIXA16 g_viewMatrix;
	D3DXMATRIXA16 g_projMatrix;

	void SetView();

	void SetProj();
protected:
public:
	Camera();

	D3DXMATRIXA16 GetViewMatrix() { return g_viewMatrix; };
	D3DXMATRIXA16 GetProjMatrix() { return g_projMatrix; };

	virtual void Update(float dt);

	virtual void Render();

	virtual void Release();
};

