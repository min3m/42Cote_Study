#include <iostream>
#include <list>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> lst;
	string str;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		auto cur = lst.begin();
		for (auto j : str)
		{
			if (j == '>')
			{
				if (cur != lst.end())
					cur++;
			}
			else if (j == '<')
			{
				if (cur != lst.begin())
					cur--;
			}
			else if (j == '-')
			{
				if (cur != lst.begin())
				{
					cur--;
					cur = lst.erase(cur);
				}
			}
			else
			{
				lst.insert(cur, j);
			}
		}
		for (auto j : lst)
			cout << j;
		cout << "\n";
		lst.clear();
	}
	return (0);
}
