#include "DXUT.h"
#include "MyD3DXMath.h"

float myMath::Float::Lerp(const float f1, const float f2, const float t)
{
	return f1 * (1 - t) + f2 * t;
}

float myMath::Vector3::Dot(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

float myMath::Vector3::LengthSq(const D3DXVECTOR3* v)
{
	return Dot(v, v);
}

float myMath::Vector3::Length(const D3DXVECTOR3* v)
{
	return sqrt(Length(v));
}

float myMath::Vector3::Distance(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2)
{
	float distX = pow(v2->x - v1->x, 2.0f);
	float distY = pow(v2->y - v1->y, 2.0f);
	float distZ = pow(v2->z - v1->z, 2.0f);

	float SqResult = distX + distY + distZ;

	return sqrt(SqResult);
}

D3DXVECTOR3 myMath::Vector3::Normalize(const D3DXVECTOR3* v)
{
	return *v / Length(v);
}

D3DXVECTOR3 myMath::Vector3::Lerp(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2, const float t)
{
	return *v1 * (1 - t) + *v2 * t;
}

D3DXMATRIX* myMath::Matrix::MatrixScaling(const D3DXMATRIX* m, D3DXVECTOR3 s)
{
	D3DXMATRIX scaleMat;
	D3DXMatrixIdentity(&scaleMat);

	scaleMat._11 = s.x;
	scaleMat._22 = s.y;
	scaleMat._33 = s.z;

	return &scaleMat;
}
