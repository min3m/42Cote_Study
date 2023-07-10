#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	queue<int> que;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		que.push(i + 1);
	}
	cout << "<";
	while (1)
	{
		if (que.size() == 1)
		{
			cout << que.front() << ">";
			break ;
		}
		for (int i = 0; i < K - 1; i++)
		{
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << ", ";
		que.pop();
	}
	return (0);
}
