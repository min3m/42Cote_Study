#include <iostream>

using namespace std;

int num[10];

int n;
int m;

void recursive(int idx)
{
	if (idx == m)
	{
		for (int i = 0; i < idx; i++)
			cout << num[i] << " ";
		cout << "\n";
		return ;
	}
	if (idx == 0)
	{
		for (int i = 0; i < n; i++)
		{
			num[idx] = i + 1;
			recursive(idx + 1);
		}
	}
	else
	{
		for (int i = num[idx - 1]; i < n; i++)
		{
			num[idx] = i + 1;
			recursive(idx + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	recursive(0);
	return (0);
}
