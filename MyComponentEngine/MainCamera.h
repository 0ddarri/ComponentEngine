#pragma once
#include "Camera.h"
#include "GameObject.h"

class MainCamera : public GameObject
{
private:
protected:
public:
	static Camera* camera;

	MainCamera();

	D3DXVECTOR3 GetCamPos();

	virtual void Update(float dt);

	virtual void Render();
};

