#include "DXUT.h"
#include "TestScene.h"


TestScene::TestScene(wstring n)
{
	name = n;
	cout << "撿" << endl;

	testObject = new GameObject();
	hierarchy.push_back(testObject);
	testLight1 = new GameObject();
	hierarchy.push_back(testLight1);
	testLight2 = new GameObject();
	hierarchy.push_back(testLight2);

	testLight1->AddComponent(new Light());
	testLight1->transform->position = { -5000,0,0 };
	testLight2->AddComponent(new Light()); // 六六 腎喜
	testLight2->transform->position = { 5000,0,0 };
	testObject->AddComponent(new Transform);
	testObject->AddComponent(new MeshRenderer);
}

void TestScene::Start()
{
	Scene::Start();
	cout << "衛濛" << endl;
}

void TestScene::Update(float dt)
{
	Scene::Update(dt);
}

void TestScene::Render()
{
	Scene::Render();
}

void TestScene::Release()
{
	Scene::Release();
	cout << "部" << endl;
}
