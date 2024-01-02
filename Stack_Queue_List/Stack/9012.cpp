#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int flag = 0;
		string str;
		stack<char> s;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '(')
				s.push('(');
			else
			{
				if (s.empty())
				{
					cout << "NO\n";
					flag = 1;
					break;
				}
				s.pop();
			}
		}
		if (!flag && s.empty())
			cout << "YES\n";
		if (!s.empty())
			cout << "NO\n";
	}
	return (0);
}
