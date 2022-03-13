#pragma once
#include "Component.h"

class Transform : public Component
{
private:
	D3DXMATRIX matrix;

protected:
public:
	Transform();
	virtual ~Transform();

	D3DXVECTOR3 position = { 0,0,0 };
	D3DXVECTOR3 rotation = { 0,0,0 };
	D3DXVECTOR3 scale = { 1,1,1 };

	virtual void Update(float dt);

	D3DXMATRIXA16 Matrix();

	virtual void Release();
};

