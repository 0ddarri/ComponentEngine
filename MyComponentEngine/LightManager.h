#pragma once
#include "Singleton.h"

class Light;

class LightManager : public Singleton<LightManager>
{
private:
protected:
public:
	list<Light*> lightList;

	void AddLight(Light* l);
	void DeleteLight(Light* l);
};

