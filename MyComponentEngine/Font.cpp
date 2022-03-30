#include "DXUT.h"
#include "Font.h"

Font::Font(int h, UINT _width, UINT _weight, bool i, LPCWSTR f)
{
	SetInfo(h, _width, _weight, i, f);
	D3DXCreateFont(DEVICE, height, width, weight, 1, italic, 1, 0, 0, 0 | FF_DONTCARE, fontName, &font);
}

void Font::SetInfo(int h, UINT _width, UINT _weight, bool i, LPCWSTR f)
{
	height = h;
	width = _width;
	weight = _weight;
	italic = i;
	fontName = f;
}

void Font::Release()
{
	font->Release();
}
