#include <iostream>

using namespace std;

int num[10];
int vis[10];

void recursive(int n, int m, int idx)
{
	if (idx == m)
	{
		for (int i = 0; i < idx; i++)
			cout << num[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
		{
			num[idx] = i + 1;
			vis[i] = 1;
			recursive(n, m, idx + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int	n, m;

	cin >> n >> m;

	recursive(n, m, 0);
	return (0);
}
