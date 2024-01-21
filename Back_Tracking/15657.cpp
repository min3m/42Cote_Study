#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, start;
int num[10];
vector<int> vec;

void recursive(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	num[cnt] = vec[idx];
	recursive(cnt + 1, idx);
	if (idx != n -1)
		recursive(cnt, idx + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vec.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	recursive(0, 0);
	return (0);
}
