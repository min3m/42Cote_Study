#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> deq;
	int n, m, l , cnt = 0;
	int num;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		deq.push_back(i + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		for (int j = 0; j < deq.size(); j++)
		{
			if (num == deq[j])
			{
				l = j + 1;
				break;
			}
		}
		if ((deq.size() + 1) / 2 >= l)
		{
			while (1)
			{
				if (num == deq.front())
				{
					deq.pop_front();
					break;
				}
				deq.push_back(deq.front());
				deq.pop_front();
				cnt++;
			}
		}
		else
		{
			while (1)
			{
				if (num == deq.front())
				{
					deq.pop_front();
					break;
				}
				deq.push_front(deq.back());
				deq.pop_back();
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return (0);
}
