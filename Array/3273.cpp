#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
vector<int> nums;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, cnt = 0;

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cin >> x;
	result.resize(x);
	for (int i = 0; i < n; i++)
	{
		if (nums[i] < x)
		{
			result[nums[i]] = 1;
			if (result[x - nums[i]] && x - nums[i] != nums[i])
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}
