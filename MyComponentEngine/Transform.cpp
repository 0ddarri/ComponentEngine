#include "DXUT.h"
#include "Transform.h"

Transform::Transform() : position({0,0,0})
{
}

Transform::~Transform()
{
}

void Transform::Update()
{
}

D3DXMATRIX Transform::Matrix()
{
	D3DXVECTOR3 pos(position);
	D3DXMATRIX trans;
	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);

	D3DXVECTOR3 rot(rotation);
	D3DXMATRIX rotX;
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMATRIX rotY;
	D3DXMatrixRotationY(&rotY, rot.y);
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);

	D3DXMATRIX angle = rotX * rotY * rotZ;

	D3DXVECTOR3 s(scale);
	D3DXMATRIX scaleMatrix;
	D3DXMatrixScaling(&scaleMatrix, s.x, s.y, s.z);

	return trans * angle * scaleMatrix;
}
