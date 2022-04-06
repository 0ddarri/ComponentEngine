#include "DXUT.h"
#include "TestScene.h"
#include "MyD3DXMath.h"


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

	testSprite = new GameObject();
	hierarchy.push_back(testSprite);

	testImage = new GameObject();
	hierarchy.push_back(testImage);

	testText = new GameObject();
	hierarchy.push_back(testText);

	testLight1->AddComponent(new Light());
	testLight1->transform->position = { -5000,0,0 };
	testLight2->AddComponent(new Light()); // 六六 腎喜
	testLight2->transform->position = { 5000,0,0 };
	testObject->AddComponent(new Transform);
	testObject->AddComponent(new MeshRenderer);

	testSprite->AddComponent(new SpriteRenderer(L"Resources/Textures/specular.jpg"));
	//testImage->AddComponent(new Image(L"Resources/Textures/specular.jpg"));

	testText->AddComponent(new Text(60, 0, 100, 0, L"Arial", L"asdfasdfasdf"));
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

void TestScene::LerpTest()
{
	D3DXVECTOR3 a(0, 0, 0);
	D3DXVECTOR3 b(1, 0, 0);
	D3DXVECTOR3 r;

	r = myMath::Vector3::Lerp(&a, &b, 0.1f);

	std::wcout << r.x << ", " << r.y << endl;
}
