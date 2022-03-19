#include "DXUT.h"
#include "Light.h"

Light::Light(D3DXCOLOR lightColor, float specular)
{
	
	color = lightColor;
	specularPower = specular;
	LightManager::Instance()->AddLight(this);
}

void Light::Update(float dt)
{
}

void Light::Release()
{
}
