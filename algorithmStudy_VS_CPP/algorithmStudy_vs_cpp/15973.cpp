#include <iostream>
#include <algorithm>
using namespace std;

struct rectangle
{
	int xMin, xMax, yMin, yMax;
};

bool isFace(const rectangle& A, const rectangle& B)
{
	return A.xMin < B.xMax && A.xMax > B.xMin && A.yMin < B.yMax && A.yMax > B.yMin;
}

bool isLine(const rectangle& A, const rectangle& B)
{
	return (A.xMax == B.xMin && A.yMin < B.yMax && A.yMax > B.yMin) ||
		(A.xMin == B.xMax && A.yMin < B.yMax && A.yMax > B.yMin) ||
		(A.yMax == B.yMin && A.xMin < B.xMax && A.xMax > B.xMin) ||
		(A.yMin == B.yMax && A.xMin < B.xMax && A.xMax > B.xMin);
}

bool isPoint(const rectangle& A, const rectangle& B) {
	return (A.xMax == B.xMin && A.yMax == B.yMin) ||
		(A.xMax == B.xMin && A.yMin == B.yMax) ||
		(A.xMin == B.xMax && A.yMax == B.yMin) ||
		(A.xMin == B.xMax && A.yMin == B.yMax);
}

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	rectangle A = {min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2)};
	cin >> x1 >> y1 >> x2 >> y2;
	rectangle B = { min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2) };

	// Face
	if (isFace(A, B) || isFace(B, A))
	{
		cout << "FACE";
	}
	else if (isLine(A, B) || isLine(B, A))
	{
		cout << "LINE";
	}
	else if (isPoint(A, B) || isPoint(B, A))
	{
		cout << "POINT";
	}
	else
	{
		cout << "NULL";
	}

	return 0;
}