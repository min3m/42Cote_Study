#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;
int board[501][501];
int vis[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q;
	int n, m, max = 0;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[j][i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[j][i] == 0 && board[j][i] == 1)
			{
				int area = 0;
				cnt++;
				Q.push(make_pair(j, i));
				vis[j][i] = 1;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					area++;
					for (int d = 0; d < 4; d++)
					{
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						else if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push(make_pair(nx, ny));
					}
				}
				if (area > max) max = area;
			}
		}
	}
	cout << cnt << "\n" << max;
	return (0);
}
