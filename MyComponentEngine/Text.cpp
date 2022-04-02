#include "DXUT.h"
#include "Transform.h"
#include "Text.h"

Text::Text()
{
}

Text::Text(int height, UINT width, UINT weight, bool italic, LPCWSTR fontname, wstring text)
{
	font = new Font(height, width, weight, italic, fontname);
	SetText(text);
}

wstring Text::SetText(wstring newText)
{
	text = newText;
	return text;
}

void Text::Update(float dt)
{
}

void Text::Render()
{
	RECT r;
	//SetRect(&r, transform->position.x - (Global::Instance()->main->camera->transform->position.x - SCW/2), transform->position.y - (Global::Instance()->main->camera->transform->position.y - SCH / 2), 0, 0);
	SetRect(&r, transform->position.x, transform->position.y, 0, 0);
	font->font->DrawTextW(nullptr, text.c_str(), -1, &r, DT_NOCLIP, D3DXCOLOR(1, 1, 1, 1));
}

void Text::Release()
{
	font->Release();
}
