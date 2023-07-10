#include <iostream>
#include <queue>

using namespace std;

#define R 1
#define G 2
#define B 3

int nrb[102][102];
int rb[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 , 0};

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			if (c == 'R') nrb[i][j] = R, rb[i][j] = R;
			else if (c == 'G') nrb[i][j] = G, rb[i][j] = R;
			else if (c == 'B') nrb[i][j] = B, rb[i][j] = B;
		}
	}
	int num_nrb = 0;
	int num_rb = 0;
	int color;
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!nrb[i][j]) continue ;
			num_nrb++;
			color = nrb[i][j];
			nrb[i][j] = 0;
			queue<pair<int, int> > que;
			que.push(make_pair(i, j));
			while (!que.empty())
			{
				pair <int, int> cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = cur.second + dx[k];
					int ny = cur.first + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
					if (!nrb[ny][nx] || nrb[ny][nx] != color) continue ;
					que.push(make_pair(ny, nx));
					nrb[ny][nx] = 0;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (!rb[i][j]) continue ;
			num_rb++;
			color = rb[i][j];
			rb[i][j] = 0;
			queue<pair<int, int> > que;
			que.push(make_pair(i, j));
			while (!que.empty())
			{
				pair <int, int> cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = cur.second + dx[k];
					int ny = cur.first + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
					if (!rb[ny][nx] || rb[ny][nx] != color) continue ;
					que.push(make_pair(ny, nx));
					rb[ny][nx] = 0;
				}
			}
		}
	}
	cout << num_nrb << " " << num_rb;
	return (0);
}
