#include "Math.h"

const Vector2 Vector2::Zero(0.0f, 0.0f);//ヘッダファイルでconst変数の定義をするとクラスをインスタンス化するたびに初期化されることになるから？

bool Math::NearZeroVector(const Vector2& vec, float epsilon)
{
	if (fabs(vec.x) <= epsilon && fabs(vec.y) <= epsilon)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Math::Atan(const Vector2& vec)
{
	return std::atan2(vec.x, vec.y);
}