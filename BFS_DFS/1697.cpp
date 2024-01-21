#include <iostream>
#include <queue>

using namespace std;
int map[200000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	queue<int> Q;

	cin >> n >> k;
	Q.push(n);
	while(1)
	{
		int cur = Q.front();
		Q.pop();
		int x = cur + 1;
		int y = cur - 1;
		int z = 2 * cur;
		if (cur == k) {
			cout << map[cur];
			break;
		}
		if (x == k || y == k || z == k) {
			cout << map[cur] + 1;
			break;
		}
		if (x < k && !map[x]){
			map[x] = map[cur] + 1;
			Q.push(x);
		}
		if (y > 0 && !map[y]){
			map[y] = map[cur] + 1;
			Q.push(y);
		}
		if (z < 2 * k && !map[z]){
			map[z] = map[cur] + 1;
			Q.push(z);
		}
	}
	return (0);
}
