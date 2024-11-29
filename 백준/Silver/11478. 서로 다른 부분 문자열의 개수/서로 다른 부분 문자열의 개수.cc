#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> s;

	map<string, int> hash;

	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j < s.length() - i + 1; j++)
			hash[s.substr(j, i)] = 1;
	}

	cout << hash.size();
}  