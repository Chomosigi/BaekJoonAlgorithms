#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int, greater<string>> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string s1, s2;
	
	for (int i = 0; i < N; i++)
	{
		cin >> s1 >> s2;
		if (s2 == "enter")
			arr[s1] = 1;
		else
			arr.erase(s1);
	}

	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << it->first << "\n";
}