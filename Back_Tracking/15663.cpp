#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int num[10];
int vis[10];
vector<int> vec;

void recursive(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && num[cnt] != vec[i])
		{
			cout << "i : " << i << "\n";
			num[cnt] = vec[i];
			vis[i] = 1;
			recursive(cnt + 1);
			vis[i] = 0;
			for (int j = cnt; j < m; j++)
				num[j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vec.resize(n);
	for(int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	recursive(0);
	return (0);
}
