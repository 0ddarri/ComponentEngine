#pragma once
#include "Global.h"
#include "Texture.h"
#include "Component.h"

class Image : public Component
{
private:
public:
	Image(wstring path);

	Texture* texture;

	virtual void Update(float dt);
	virtual void Render();

	virtual void Release();

};

