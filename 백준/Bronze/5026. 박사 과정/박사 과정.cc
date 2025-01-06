#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		string s;
		cin >> s;
		if (s == "P=NP")
			cout << "skipped" << '\n';
		else
		{
			int p, left = 0, right = 0;
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == '+')
					p = i;
			}
			for (int i = 0; i < p; i++)
				left = left * 10 + s[i] - '0';
			for(int i = p + 1; i < s.length(); i++)
				right = right * 10 + s[i] - '0';
			cout << left + right << '\n';
		}
	}
}