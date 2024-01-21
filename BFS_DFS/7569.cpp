#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define X get<0>
#define Y get<1>
#define Z get<2>

int arr[101][101][101];
int visited[101][101][101];
int nx[6] = {1, -1, 0, 0, 0, 0};
int ny[6] = {0, 0, 1, -1, 0, 0};
int nz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h, max = 0;
	queue <tuple<int, int, int> > Q;
	cin >> m >> n >> h;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				cin >> arr[l][j][i];
				if (arr[l][j][i] == 1)
				{
					Q.push(make_tuple(l, j, i));
					visited[l][j][i] = 0;
				}
			}
		}
	}
	while(!Q.empty())
	{
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 6; i++)
		{
			int dx = X(cur) + nx[i];
			int dy = Y(cur) + ny[i];
			int dz = Z(cur) + nz[i];
			if (dx < 0 || dx >= m || dy < 0 || dy >= n || dz < 0 || dz >= h) continue;
			if (arr[dx][dy][dz]) continue;
			Q.push(make_tuple(dx, dy, dz));
			visited[dx][dy][dz] = visited[X(cur)][Y(cur)][Z(cur)] + 1;
			arr[dx][dy][dz] = 1;
			if (max < visited[dx][dy][dz]) max = visited[dx][dy][dz];
		}
	}
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				if (arr[l][j][i] == 0)
				{
					cout << "-1\n";
					return (0);
				}
			}
		}
	}
	cout << max << "\n";
	return (0);
}
