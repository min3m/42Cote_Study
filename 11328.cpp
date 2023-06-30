#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int hash1[26] = {0};
		int hash2[26] = {0};
		int flag = 0;
		string c1, c2;
		cin >> c1 >> c2;
		if (c1.length() != c2.length())
		{
			cout << "Impossible\n";
			continue;
		}
		for (int j = 0; j < c1.length(); j++)
			hash1[c1[j] - 97]++;
		for (int j = 0; j < c2.length(); j++)
			hash2[c2[j] - 97]++;
		for (int j = 0; j < 26; j++)
		{
			if (hash1[j] != hash2[j])
			{
				cout << "Impossible\n";
				flag = 1;
				break ;
			}
		}
		if (!flag)
			cout << "Possible\n";
	}
	return (0);
}
