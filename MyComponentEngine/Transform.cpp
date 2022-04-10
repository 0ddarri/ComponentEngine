#include "DXUT.h"
#include "Transform.h"
#include "MyD3DXMath.h"

Transform::Transform()
{
	position = D3DXVECTOR3(0, 0, 0);
	rotation = D3DXVECTOR3(0, 0, 0);
	scale = D3DXVECTOR3(1, 1, 1);
}

Transform::~Transform()
{
}

void Transform::Update(float dt)
{
}

D3DXMATRIXA16 Transform::Matrix()
{
	D3DXVECTOR3 pos(position);
	D3DXMATRIXA16 trans;
	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);

	D3DXVECTOR3 rot(rotation);
	D3DXMATRIXA16 rotX;
	D3DXMatrixRotationX(&rotX, D3DXToRadian(rot.x));
	D3DXMATRIXA16 rotY;
	D3DXMatrixRotationY(&rotY, D3DXToRadian(rot.y));
	D3DXMATRIXA16 rotZ;
	D3DXMatrixRotationZ(&rotZ, D3DXToRadian(rot.z));

	D3DXMATRIXA16 angle = rotZ * rotX * rotY;

	D3DXVECTOR3 s(scale);
	D3DXMATRIXA16 scaleMatrix;
	//D3DXMatrixScaling(&scaleMatrix, s.x, s.y, s.z);
	scaleMatrix = *myMath::Matrix::MatrixScaling(&scaleMatrix, s);

	return scaleMatrix * angle * trans;
}

void Transform::Release()
{
	position = { 0,0,0 };
	rotation = { 0,0,0 };
	scale = { 1,1,1 };
}
