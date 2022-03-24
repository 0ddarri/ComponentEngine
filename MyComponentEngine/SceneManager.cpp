#include "DXUT.h"
#include "SceneManager.h"

void SceneManager::AddScene(Scene* n)
{
	for (auto it : g_SceneList)
	{
		if (it->name == n->name) return;
	}
	g_SceneList.push_back(n);
	cout << "Add Scene: " << n->name.c_str() << endl;
}

bool SceneManager::ChangeScene(Scene* n)
{
	newScene = n;
	if (curScene != nullptr)
	{
		curScene->Release();
	}
	curScene = newScene;
	curScene->Start();
	return true;
}

bool SceneManager::ChangeScene(wstring name)
{
	newScene = FindScene(name);
	if (curScene != nullptr)
	{
		curScene->Release();
	}
	curScene = newScene;
	curScene->Start();
	return true;
}

bool SceneManager::ChangeScene(int num)
{
	newScene = FindScene(num);
	if (curScene != nullptr)
	{
		curScene->Release();
	}
	curScene = newScene;
	curScene->Start();
	return true;
}

Scene* SceneManager::FindScene(wstring name)
{
	for (auto it : g_SceneList)
	{
		if (it->name == name) return it;
	}
	cout << "Can't Find Scene: " << name.c_str() << endl;
	return nullptr;
}

Scene* SceneManager::FindScene(int num)
{
	if (g_SceneList.size() < num)
	{
		cout << "Can't Find Scene: " << num << endl;
		return nullptr;
	}
	Scene* n = g_SceneList[num];
	return n;
}
