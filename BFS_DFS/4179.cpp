#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

string board[1002];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > Q1;
	queue<pair<int, int> > Q2;
	int r,c;

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
		for (int j = 0; j < c; j++)
		{
			dist1[i][j] = -1;
			dist2[i][j] = -1;
			if (board[i][j] == 'F')
			{
				dist1[i][j] = 0;
				Q1.push(make_pair(i, j));
			}
			else if(board[i][j] == 'J')
			{
				dist2[i][j] = 0;
				Q2.push(make_pair(i, j));
			}
		}
	}
	while (!Q1.empty())
	{
		pair<int, int> cur = Q1.front();
		Q1.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
			if (dist1[nx][ny] != -1 || board[nx][ny] == '#') continue;
			Q1.push(make_pair(nx, ny));
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
		}
	}
	while (!Q2.empty())
	{
		pair<int, int> cur = Q2.front();
		Q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx >= r || nx < 0 || ny >= c || ny < 0)
			{
				cout << dist2[cur.X][cur.Y] + 1;
				return (0);
			}
			if (dist2[nx][ny] != -1 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist2[nx][ny] + 1 >= dist1[nx][ny]) continue;
			Q2.push(make_pair(nx, ny));
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
		}
	}
	cout << "IMPOSSIBLE";
	return (0);
}
