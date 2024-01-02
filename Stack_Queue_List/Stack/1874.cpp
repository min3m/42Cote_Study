#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	vector<char> result;
	int n;
	int m = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		while(1)
		{
			if (s.empty())
			{
				s.push(m++);
				result.push_back('+');
			}
			else
			{
				if (s.top() == num)
				{
					result.push_back('-');
					s.pop();
					break;
				}
				else if (s.top() > num)
				{
					cout << "NO\n";
					return (0);
				}
				else
				{
					result.push_back('+');
					s.push(m++);
				}
			}
		}
	}
	for (auto i : result)
		cout << i << '\n';
	return (0);
}
