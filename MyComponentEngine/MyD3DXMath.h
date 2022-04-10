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
		float Dot(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2); // 내적


		float LengthSq(const D3DXVECTOR3* v); // 벡터의 길이

		float Length(const D3DXVECTOR3* v); // 벡터의 길이


		float Distance(const D3DXVECTOR3* v1, const D3DXVECTOR3* v2); // 벡터와 벡터 사이 거리


		D3DXVECTOR3 Normalize(const D3DXVECTOR3* v); // 벡터 정규화


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