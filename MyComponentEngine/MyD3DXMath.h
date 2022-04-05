#pragma once
#include <cmath>
#include "DXUT.h"

namespace myMath
{
	// Float

	// Vector2

	// Vector3
	namespace Vector3
	{
		float Dot(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2) // ����
		{
			return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
		}

		float LengthSq(const D3DXVECTOR3* v) // ������ ����
		{
			return Dot(v, v);
		}
		float Length(const D3DXVECTOR3* v) // ������ ����
		{
			return sqrt(Length(v));
		}

		float Distance(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2) // ���Ϳ� ���� ���� �Ÿ�
		{
			float distX = pow(v2->x - v1->x, 2.0f);
			float distY = pow(v2->y - v1->y, 2.0f);
			float distZ = pow(v2->z - v1->z, 2.0f);

			float SqResult = distX + distY + distZ;

			return sqrt(SqResult);
		}

		D3DXVECTOR3 Normalize(const D3DXVECTOR3* v) // ���� ����ȭ
		{
			D3DXVECTOR3 n;
			float length = Length(v);
			n = *v / length;

			return n;
		}
	}

	// Vector4

	// Matrix

	// Quaternion
}