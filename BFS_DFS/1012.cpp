#include <iostream>
#include <queue>
#define X first
#define Y second

int map[51][51];

int nx[4] = {-1, 1, 0, 0};
int ny[4] = {0, 0, -1, 1};

using namespace std;

int main()
{
	queue<pair<int, int> > Q;
	int t, m, n, k;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int num = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for(int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				if (map[l][j] == 1)
				{
					num++;
					Q.push(make_pair(l, j));
					map[l][j] = 0;
					while (!Q.empty())
					{
						pair<int, int> cur = Q.front();
						Q.pop();
						for (int d = 0; d < 4; d++)
						{
							int dx = cur.X + nx[d];
							int dy = cur.Y + ny[d];
							if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
							if (!map[dx][dy]) continue;
							Q.push(make_pair(dx, dy));
							map[dx][dy] = 0;
						}
					}
				}
			}
		}
		cout << num << "\n";
	}
	return (0);
}
