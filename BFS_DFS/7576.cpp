#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> >Q;
	int n, m, day = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[j][i];
			if(board[j][i] == 1)
				Q.push(make_pair(j, i));
			else
				dist[j][i] = -1;
		}
	}
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (dist[nx][ny] != -1 || board[nx][ny]) continue;
			Q.push(make_pair(nx, ny));
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			board[nx][ny] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == 0)
			{
				cout << "-1";
				return (0);
			}
			day = max(day, dist[j][i]);
		}
	}
	cout << day;
	return (0);
}
