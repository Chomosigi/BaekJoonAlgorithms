#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mon1;
map<int, string> mon2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		mon1[s] = i;
		mon2[i] = s;
	}
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		int num;
		num = atoi(s.c_str());
		if (num == 0)
			cout << mon1[s] + 1 << "\n";
		else
		{
			num -= 1;
			cout << mon2[num] << "\n";
		}
	}
}