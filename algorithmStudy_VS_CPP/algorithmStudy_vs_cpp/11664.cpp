#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Vector3
{
	double x, y, z;

	Vector3 operator -(const Vector3& v) const
	{
		return { x - v.x, y - v.y, z - v.z };
	}

	Vector3 operator +(const Vector3& v) const
	{
		return { x + v.x,  y + v.y, z + v.z };
	}

	Vector3 operator *(double s) const
	{
		return { x * s, y * s, z * s };
	}

	double Dot(const Vector3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	double Magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	double DistanceTo(const Vector3& v) const
	{
		return (*this - v).Magnitude();
	}
};

int main()
{
	int ax, ay, az, bx, by, bz, cx, cy, cz;
	cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

	Vector3 A = { ax, ay, az };
	Vector3 B = { bx, by, bz };
	Vector3 P = { cx, cy, cz };

	Vector3 AB = B - A;
	Vector3 AP = P - A;
	
	double ab = AB.Dot(AB);
	double ap_ab = AP.Dot(AB);

	double t = ap_ab / ab;
	t = max(0.0, min(1.0, t));

	Vector3 closest = A + AB * t;

	cout.precision(10);
	cout << fixed << P.DistanceTo(closest);

	return 0;
}