#include <iostream>

using namespace std;

int numbers[10];
int cnt = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string room;

	cin >> room;
	for (int i = 0; i < room.length(); i++)
	{
		int n = room[i] - 48;
		if (cnt != numbers[n])
			numbers[n]++;
		else
		{
			if (n == 6 && cnt != numbers[9])
				numbers[9]++;
			else if (n == 9 && cnt != numbers[6])
				numbers[6]++;
			else
			{
				cnt++;
				numbers[n]++;
			}
		}
	}
	cout << cnt;
	return 0;
}
