#pragma once
#include <iostream>

class Vector2;

namespace Math {

	static const float Pi = 3.1415926535f;

	static const float TwoPi = Pi * 2;

	inline float ToRdians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool NearZeroVector(const Vector2& vec, float epsilon = 0.001f);

	inline float Cos(float rot)
	{
		return std::cos(rot);
	}

	inline float Sin(float rot)
	{
		return std::sin(rot);
	}

	float Atan(const Vector2& vec);
}

	class Vector2
	{
	public:
		float x;
		float y;

		explicit Vector2(float x, float y) : x(x), y(y)//explicitを使うと単純な数値を代入する初期化ができない(逆に使っていなかったらできる)
		{}
		Vector2() : x(0.0f), y(0.0f)
		{}

		static const friend Vector2 operator+ (const Vector2& a, const Vector2& b)
		{
			Vector2 temp(a.x + b.x, a.y + b.y);
			return temp;
		}

		static const friend Vector2 operator- (const Vector2& a, const Vector2& b)
		{
			Vector2 temp(a.x - b.x, a.y - b.y);
			return temp;
		}

		static const friend Vector2 operator* (const Vector2 & vec, float scalor)//
		{
			Vector2 temp(vec.x * scalor, vec.y * scalor);
			return temp;
		}

		static friend Vector2 operator* (float scalor, const Vector2& vec)
		{
			Vector2 temp(vec.x, vec.y);
			temp.x *= scalor;
			temp.y *= scalor;
			return temp;
		}

		static const friend Vector2 operator* (const Vector2& a, const Vector2& b)
		{
			Vector2 temp(a.x * b.x, a.y * b.y);
			return temp;
		}

		Vector2 &operator += (const Vector2& vec)
		{
			this->x += vec.x;
			this->y += vec.y;
			return *this; //代入演算子のオーバーロードはそのクラスの実体を返す必要があるため * を付ける, thisは右辺値？
		}

		float LengthSquared() const
		{
			float x = this->x * this->x;
			float y = this->y * this->y;
			return x + y;
		}

		float Length() const
		{
			float temp = this->LengthSquared();
			return sqrt(temp);
		}

		void Normalize()
		{
			if (this->LengthSquared() != 0)
			{
				this->x /= this->Length();
				this->y /= this->Length();
			}
			else
			{
				std::cout << "Can't Normalize" << std::endl;
			}
		}

		static friend const Vector2 Normalize(const Vector2& vec)
		{
			if (vec.LengthSquared() != 0)
			{
				Vector2 temp;
				temp.x = vec.x / vec.Length();
				temp.y = vec.y / vec.Length();
				return temp;
			}
			else
			{
				std::cout << "Can't Normalize" << std::endl;
				return vec;
			}
		}

		static friend const Vector2 Verticalize(Vector2& vec)
		{
			if (vec.LengthSquared() != 0)
			{
				float temp = Math::Atan(vec);
				return Vector2(Math::Sin(temp + Math::Pi / 2), Math::Cos(temp + Math::Pi / 2));
			}
			else
			{
				std::cout << "Can't Verticalize" << std::endl;
				return vec;
			}
		}

		static const Vector2 Zero;
	};
