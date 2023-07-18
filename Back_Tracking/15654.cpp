#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m;
int num[10];
int vis[10];
int input[10];

void recursive(int idx)
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
		if (!vis[i])
		{
			num[idx] = input[i];
			vis[i] = 1;
			recursive(idx + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	recursive(0);
	return (0);
}
