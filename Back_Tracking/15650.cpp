// #include <iostream>

// using namespace std;

// int num[10];

// int n;
// int m;

// void recursive(int idx)
// {
// 	if (idx == m)
// 	{
// 		for (int i = 0; i < idx; i++)
// 			cout << num[i] << " ";
// 		cout << "\n";
// 		return ;
// 	}
// 	if (idx == 0)
// 	{
// 		for (int i = 0; i < n; i++)
// 		{
// 			num[idx] = i + 1;
// 			recursive(idx + 1);
// 		}
// 	}
// 	else
// 	{
// 		for (int i = num[idx - 1]; i < n; i++)
// 		{
// 			num[idx] = i + 1;
// 			recursive(idx + 1);
// 		}
// 	}
// }

// int main()
// {
// 	cin >> n >> m;
// 	recursive(0);
// 	return (0);
// }
#include <iostream>

using namespace std;
int num[10];

void backtrack(int n, int m, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt == 0)
		{
			num[cnt] = i;
			backtrack(n, m ,cnt + 1);
		}
		else if (cnt != 0 && num[cnt - 1] < i)
		{
			num[cnt] = i;
			backtrack(n, m ,cnt + 1);
		}
	}
}

int main()
{
	int n, m;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	backtrack(n, m, 0);
	return (0);
}
