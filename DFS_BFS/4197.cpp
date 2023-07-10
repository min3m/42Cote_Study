#include <iostream>
#include <queue>

using namespace std;

#define G 0;
#define W 1;
#define J 2;
#define F 3;

int j[1002][1002];
int f[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
	int r,c;
	queue<pair<int, int>> que;

	cin >> r >> c;

	for(int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char c;
			cin >> c;
		}
	}
	return (0);
}
