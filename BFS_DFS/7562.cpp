#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;
int nx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int ny[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l, x, y, x1, y1;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int map[301][301] = {0,};
		queue<pair<int, int> > Q;
		int flag = 0;
		cin >> l >> x >> y >> x1 >> y1;
		map[x][y] = 1;
		Q.push(make_pair(x, y));
		if (x == x1 && y == y1)
		{
			cout << "0\n";
			flag = 1;
		}
		while(!Q.empty())
		{
			if (flag == 1) break;
			pair<int, int> cur = Q.front();
			Q.pop();
			for(int j = 0; j < 8; j++)
			{
				int dx = cur.X + nx[j];
				int dy = cur.Y + ny[j];
				if (dx < 0 || dx >= l || dy < 0 || dy >= l) continue;
				if (map[dx][dy]) continue;
				if (dx == x1 && dy == y1)
				{
					cout << map[cur.X][cur.Y] << "\n";
					flag = 1;
					break;
				}
				Q.push(make_pair(dx, dy));
				map[dx][dy] = map[cur.X][cur.Y] + 1;
			}
		}
	}
	return (0);
}
