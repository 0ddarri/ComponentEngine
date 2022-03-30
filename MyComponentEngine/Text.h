#pragma once
#include "Global.h"
#include "Font.h"
#include "Component.h"

class Text : public Component
{
private:
public:
	Text();
	Text(int height, UINT width, UINT weight, bool italic, LPCWSTR fontname, wstring text);

	Font* font;
	wstring text;

	wstring SetText(wstring newText);

	virtual void Update(float dt);
	virtual void Render();
	virtual void Release();
};

