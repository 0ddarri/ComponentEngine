#pragma once
#include <cmath>
#include <D3DX10.h>

namespace myMath
{
	// Float
	namespace Float
	{
		float Lerp(const float f1, const float f2, const float t)
		{
			return f1 * (1 - t) + f2 * t;
		}
	}

	// Vector2

	// Vector3
	namespace Vector3
	{
		float Dot(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2) // ≥ª¿˚
		{
			return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
		}

		float LengthSq(const D3DXVECTOR3* v) // ∫§≈Õ¿« ±Ê¿Ã
		{
			return Dot(v, v);
		}
		float Length(const D3DXVECTOR3* v) // ∫§≈Õ¿« ±Ê¿Ã
		{
			return sqrt(Length(v));
		}

		float Distance(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2) // ∫§≈ÕøÕ ∫§≈Õ ªÁ¿Ã ∞≈∏Æ
		{
			float distX = pow(v2->x - v1->x, 2.0f);
			float distY = pow(v2->y - v1->y, 2.0f);
			float distZ = pow(v2->z - v1->z, 2.0f);

			float SqResult = distX + distY + distZ;

			return sqrt(SqResult);
		}

		D3DXVECTOR3 Normalize(const D3DXVECTOR3* v) // ∫§≈Õ ¡§±‘»≠
		{
			return *v / Length(v);
		}

		D3DXVECTOR3 Lerp(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2, const float t)
		{
			return *v1 * (1 - t) + *v2 * t;
		}
	}

	// Vector4

	// Matrix
	namespace Matrix
	{
		D3DXMATRIX* MatrixScaling(const D3DXMATRIX* m, D3DXVECTOR3 s)
		{
			D3DXMATRIX scaleMat;
			D3DXMatrixIdentity(&scaleMat);

			scaleMat._11 = s.x;
			scaleMat._22 = s.y;
			scaleMat._33 = s.z;

			return &scaleMat;
		}
	}

	// Quaternion
}