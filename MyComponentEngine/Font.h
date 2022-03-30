#pragma once
class Font
{
private:
public:
	Font(int h, UINT _width, UINT _weight, bool i, LPCWSTR f);

	LPD3DXFONT font;

	int height;
	UINT width;
	UINT weight;
	bool italic;
	LPCWSTR fontName;

	void SetInfo(int h, UINT _width, UINT _weight, bool i, LPCWSTR f);

	void Release();
};