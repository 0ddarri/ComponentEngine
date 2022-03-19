#pragma once
#include "Component.h"
#include "LightManager.h"

class Light : public Component
{
private:
	D3DXCOLOR color;
	float specularPower;
protected:
public:
	Light(D3DXCOLOR lightColor = { 1,1,1,1 }, float specular = 20.0f);

	D3DXCOLOR GetColor() { return color; }
	float GetSpecularPower() { return specularPower; }

	void SetColor(D3DXCOLOR newColor) { color = newColor; }
	void SetSpecularPower(float newPower) { specularPower = newPower; }

	virtual void Update(float dt);
	virtual void Release();
};
