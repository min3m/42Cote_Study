#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> lst;
	string input;
	int m;
	char c;
	char s;

	cin >> input >> m;
	for (auto i : input)
		lst.push_back(i);
	auto cur = lst.end();
	for(int i = 0; i < m; i++)
	{
		cin >> c;
		if (c == 'P')
		{
			cin >> s;
			lst.insert(cur, s);
		}
		else if (c == 'L')
		{
			if (cur != lst.begin())
				cur--;
		}
		else if (c == 'D')
		{
			if (cur != lst.end())
				cur++;
		}
		else if (c == 'B')
		{
			if (cur != lst.begin())
			{
				cur--;
				cur = lst.erase(cur);
			}
		}
	}
	for (auto i : lst)
		cout << i;
	cout << "\n";
	return (0);
}
