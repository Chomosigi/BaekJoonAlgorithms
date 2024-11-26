#include <iostream>
#include <map>

using namespace std;

map<string, int> list;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, cnt = 0;

	cin >> N >> M;

	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		list[s] = 0;
	}

	for (int j = 0; j < M; j++)
	{
		cin >> s;
		if (list.find(s) != list.end())
		{
			list[s] = 1;
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if (iter->second == 1)
			cout << iter->first << "\n";
	}
}