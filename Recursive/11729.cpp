#include <iostream>

using namespace std;

void recursive(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return ;
	}
	recursive(n - 1, from , to, by);
	cout << from << " " << to << "\n";
	recursive(n - 1, by, from, to);

}

int main()
{
	int n;

	cin >> n;

	cout << (1 << n) - 1 << "\n";
	recursive(n, 1, 2, 3);
	return (0);
}
