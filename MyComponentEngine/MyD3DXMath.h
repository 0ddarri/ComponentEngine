#pragma once

namespace myMath
{
	// Float
	namespace Float
	{
		float Lerp(const float f1, const float f2, const float t);
	}

	// Vector2

	// Vector3
	namespace Vector3
	{
		float Dot(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2); // ����


		float LengthSq(const D3DXVECTOR3* v); // ������ ����

		float Length(const D3DXVECTOR3* v); // ������ ����


		float Distance(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2); // ���Ϳ� ���� ���� �Ÿ�


		D3DXVECTOR3 Normalize(const D3DXVECTOR3* v); // ���� ����ȭ


		D3DXVECTOR3 Lerp(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2, const float t);

	}

	// Vector4

	// Matrix
	namespace Matrix
	{
		D3DXMATRIX* MatrixScaling(const D3DXMATRIX* m, D3DXVECTOR3 s);

	}

	// Quaternion
}