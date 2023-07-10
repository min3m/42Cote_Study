#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N;
	int v;
	int count = 0;
	map<int, int> m;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		m[num]++;
	}
	cin >> v;
	cout << m[v] << endl;
	return (0);
}
