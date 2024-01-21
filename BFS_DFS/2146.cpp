#include <iostream>
#include <queue>
#define X first
#define Y second

int map[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0 ,0, -1, 1};

using namespace std;

int main()
{
	int n, min = 1000000;
	int land = -1;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				queue<pair<int, int> > Q;
				Q.push(make_pair(i, j));
				map[i][j] = land;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int d = 0; d < 4; d++)
					{
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (!map[nx][ny] || map[nx][ny] != 1) continue;
						Q.push(make_pair(nx, ny));
						map[nx][ny] = land;
					}
				}
				--land;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j])
			{
				int visited[101][101] = {0,};
				int loc = map[i][j];
				int flag = 0;

				queue<pair<int, int> > Q;
				Q.push(make_pair(i, j));
				visited[i][j] = 1;
				while (!Q.empty())
				{
					pair<int, int> cur;
					cur = Q.front();
					Q.pop();
					for (int d = 0; d < 4; d++)
					{
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (map[nx][ny] == loc) continue;
						if (visited[nx][ny]) continue;
						if (map[nx][ny])
						{
							if (min > visited[cur.X][cur.Y]) min = visited[cur.X][cur.Y];
							flag = 1;
							break;
						}
						Q.push(make_pair(nx, ny));
						visited[nx][ny] = visited[cur.X][cur.Y] + 1;
						if (visited[nx][ny] > min) flag = 1;
					}
					if (flag) break;
				}
				// for (int l = 0; l < n; l++)
				// {
				// 	for (int k = 0; k < n; k++)
				// 	{
				// 		cout << visited[l][k] << " ";
				// 	}
				// 	cout << "\n";
				// }
				// cout << "\n";
			}
		}
	}
	cout << min - 1 << "\n";
	return (0);
}
