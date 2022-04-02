#pragma once
#include "Singleton.h"
#include "Scene.h"

class SceneManager : public Singleton<SceneManager>
{
private:
	vector<Scene*> g_SceneList;
protected:
public:
	Scene* curScene = nullptr;
	Scene* newScene = nullptr;

	void AddScene(Scene* n);

	bool ChangeScene(Scene* n);
	bool ChangeScene(wstring name);
	bool ChangeScene(int num);

	Scene* FindScene(wstring name);
	Scene* FindScene(int num);

	void ResetDevice();
	void LostDevice();
};

