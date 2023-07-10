#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int count = 0;
	int i = 0;
	int j = 0;
	string c1;
	string c2;

	cin >> c1;
	cin >> c2;

	sort(c1.begin(), c1.end());
	sort(c2.begin(), c2.end());

	while(i < c1.length() && j < c2.length())
	{
		if (c1[i] == c2[j])
		{
			i++;
			j++;
		}
		else if (c1[i] > c2[j])
		{
			count++;
			j++;
		}
		else if (c1[i] < c2[j])
		{
			count++;
			i++;
		}
	}
	if (i != c1.length())
		count += c1.length() - i;
	else if (j != c2.length())
		count += c2.length() - j;
	cout << count << "\n";
	return (0);
}
