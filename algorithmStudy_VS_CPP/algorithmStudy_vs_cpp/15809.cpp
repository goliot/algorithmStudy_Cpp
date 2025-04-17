#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int parent[100001]; //<루트 부모, 병력 수>
int troops[100001];

int find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = find(parent[x]);
	}

	return parent[x];
}


void countGroups() {
	int count = 0;
	vector<int> remainCountries;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i && troops[i] > 0) {
			count++;
			remainCountries.push_back(troops[i]);
		}
	}
	cout << count << '\n';
	sort(remainCountries.begin(), remainCountries.end());
	for (int i : remainCountries)
	{
		cout << i << " ";
	}
}

vector<int> getGroupMembers(int root)
{
	vector<int> members;
	for (int i = 1; i <= n; i++)
	{
		if (find(i) == root) {
			members.push_back(i);
		}
	}
	return members;
}

void unionSet(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);
	if (rootA != rootB)
	{
		troops[rootA] += troops[rootB];
		parent[rootB] = rootA;
	}
}

void war(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB) return;

	if (troops[rootA] == troops[rootB]) {
		vector<int> groupA = getGroupMembers(rootA);
		vector<int> groupB = getGroupMembers(rootB);

		for (int i : groupA) troops[i] = 0;
		for (int i : groupB) troops[i] = 0;

		return;
	}

	int winner = troops[rootA] > troops[rootB] ? rootA : rootB;
	int loser = troops[rootA] < troops[rootB] ? rootA : rootB;

	// 승자 병력에서 패자 병력을 빼고
	troops[winner] -= troops[loser];

	// 패자 그룹의 멤버들 부모를 승자 부모로 설정
	vector<int> loserGroup = getGroupMembers(loser);
	for (int i : loserGroup) {
		parent[i] = winner;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		troops[i] = x;
	}

	for (int i = 1; i <= m; i++)
	{
		int o, p, q;
		cin >> o >> p >> q;

		if (o == 1)
		{
			unionSet(p, q);
		}
		if (o == 2)
		{
			war(p, q);
		}
	}

	countGroups();

	return 0;
}