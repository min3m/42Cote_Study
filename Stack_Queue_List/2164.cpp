#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> que;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		que.push(i);
	}
	while (que.size() != 1)
	{
		que.pop();
		int num = que.front();
		que.pop();
		que.push(num);
	}
	cout << que.front() << "\n";
	return (0);
}
