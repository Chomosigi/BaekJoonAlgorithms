#include <iostream>
#include <map>

using namespace std;

map<string, string> mem;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, s_n;

	cin >> N >> s_n;

	for (int i = 0; i < N; i++)
	{
		string id, pw;
		cin >> id >> pw;
		mem[id] = pw;
	}

	for (int i = 0; i < s_n; i++)
	{
		string id;
		cin >> id;
		cout << mem[id] << "\n";
	}
}