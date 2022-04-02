#pragma once
#include "Singleton.h"
#include "MainCamera.h"

class Global : public Singleton<Global>
{
private:
	LPD3DXSPRITE sprite;
public:
	Global();
	void CreateSprite();
	LPD3DXSPRITE GetSprite();

	void LostDevice();
	void ResetDevice();

	MainCamera* main;

	void Update(float dt);

	void Render();

	void Release();
};

