#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int arr[100000];

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int m;
		cin >> m;
		string nums;
		cin >> nums;
		bool err = false;
		bool rev = false;
		int cnt = 0;
		int lidx = 0;
		int ridx = 0;
		for (int i = 0; i < m; i++)
			arr[i] = 0;
		for (int i = 1; i < nums.length() - 1; i++)
		{
			if (nums[i] != ',')
				arr[cnt] = arr[cnt] * 10 + nums[i] - '0';
			else
				cnt++;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'R')
				rev = rev ^ 1;
			if (s[i] == 'D')
			{
				if (lidx == m - ridx)
				{
					err = true;
					break;
				}
				if (!rev)
					lidx++;
				else
					ridx++;
			}
		}
		if (err == true)
			cout << "error\n";
		else
		{
			cout << '[';
			if (rev)
			{
				for (int i = m - ridx - 1; i >= lidx; i--)
				{
					cout << arr[i];
					if (i != lidx)
						cout << ",";
				}
			}
			else if (!rev)
			{
				for (int i = lidx; i < m - ridx; i++)
				{
					cout << arr[i];
					if (m - ridx - 1 != i)
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}