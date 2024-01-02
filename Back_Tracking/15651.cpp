#include <iostream>

using namespace std;

int n;
int m;
int num[10];

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
		num[idx] = i + 1;
		recursive(idx + 1);
	}
}

int main()
{
	cin >> n >> m;
	recursive(0);
	return (0);
}
