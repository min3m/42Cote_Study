#include <iostream>

using namespace std;

void recursive(int i, int j, int n)
{
	if ( (i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << " ";
	else if (n / 3 == 0)
		cout << "*";
	else
		recursive(i, j, n / 3);
}

int main()
{
	int n;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			recursive(i, j, n);
		}
		cout << "\n";
	}
	return (0);
}
