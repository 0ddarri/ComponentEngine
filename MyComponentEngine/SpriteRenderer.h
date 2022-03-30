#pragma once
#include "Global.h"
#include "Texture.h"
#include "Component.h"

class SpriteRenderer : public Component
{
private:
protected:
public:
	SpriteRenderer(wstring path);

	Texture* texture;

	virtual void Update(float dt);
	virtual void Render();

	virtual void Release();
};

