#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct line {
	int x;
	int y;
	int cost;
};

vector<line> road;
int parent[1001];

int find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = find(parent[x]);
	}

	return parent[x];
}

void unionSet(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);

	if (rootA != rootB)
	{
		parent[rootB] = rootA;
	}
}

bool isConnected(int a, int b)
{
	return find(a) == find(b);
}

bool cmp(line x, line y) {
	if (x.cost > y.cost) 
		return true;

	return false;
}

int main()
{
	for (int i = 0; i < 1001; i++) 
	{
		parent[i] = i;
	}

	int p, w, c, v, ws, we, ww;
	cin >> p >> w;
	cin >> c >> v;

	for (int i = 0; i < w; i++)
	{
		cin >> ws >> we >> ww;
		road.push_back({ ws, we, ww });
	}
	sort(road.begin(), road.end(), cmp);

	for (auto i : road)
	{
		int x = i.x;
		int y = i.y;
		int cost = i.cost;
		unionSet(x, y);
		if (isConnected(c, v))
		{
			cout << cost;
			break;
		}
	}

	return 0;
}