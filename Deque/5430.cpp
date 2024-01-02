#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string func, arr;
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> func >> n >> arr;
		bool r = false;
		bool flag = true;
		deque<int> deq;
		string tmp;
		for(int j = 0; j < arr.size(); j++)
		{
			if (isdigit(arr[j]))
				tmp += arr[j];
			else
			{
				if (n == 0)
					tmp = "";
				if (tmp.size())
				{
					deq.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		for (int j = 0; j < func.size(); j ++)
		{
			if (func[j] == 'R')
				r = !r;
			else
			{
				if (!deq.size())
				{
					cout << "error";
					flag = false;
					break;
				}
				if (r)
					deq.pop_back();
				else
					deq.pop_front();
			}
		}
		if (flag)
		{
			cout << "[";
			if (r)
			{
				for (int j = deq.size() - 1; j >= 0 ; j--)
				{
					cout << deq[j];
					if (j != 0)
						cout << ",";
				}
			}
			else
			{
				for (int j = 0; j < deq.size(); j++)
				{
					cout << deq[j];
					if (j != deq.size() - 1)
						cout << ",";
				}
			}
			cout << "]";
		}
		cout << "\n";
	}
	return (0);
}
