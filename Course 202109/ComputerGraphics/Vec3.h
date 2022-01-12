#pragma once

class Vec3
{
public:
	Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
	Vec3(float a, float b, float c) : x(a), y(b), z(c) {};

	const float GetX() const { return x; }
	const float GetY() const { return y; }
	const float GetZ() const { return z; }
	const float GetNorm() const { return sqrtf(x * x + y * y + z * z); }

	Vec3 operator+(const Vec3& otr) const { return Vec3(x + otr.GetX(), y + otr.GetY(), z + otr.GetZ()); }
	Vec3 operator-() const { return Vec3(-x, -y, -z); }
	Vec3 operator-(const Vec3& otr) const { return *this + (-otr); }

	Vec3 Scale(float t) { return Vec3(x * t, y * t, z * t); }
	Vec3 Cross(const Vec3& otr) const { return Vec3(y * otr.GetZ() - z * otr.GetY(), z * otr.GetX() - x * otr.GetZ(), x * otr.GetY() - y * otr.GetX()); }

	void Normalize() {
		auto norm = GetNorm();
		x /= norm; y /= norm; z /= norm;
	}

private:
	float x, y, z;
};