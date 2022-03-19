#include "DXUT.h"
#include "LightManager.h"


void LightManager::AddLight(Light* l)
{
	for (auto it : lightList)
	{
		if (it == l)
		{
			cout << "Light Is Already In" << endl;
			return;
		}
	}
	lightList.push_back(l);
	cout << "Add Light : " << lightList.size() << endl;
}

void LightManager::DeleteLight(Light* l)
{
	for (auto it : lightList)
	{
		if (it == l)
		{
			lightList.remove(it);
			cout << "Remove Light : " << lightList.size() << endl;
			return;
		}
	}
}
