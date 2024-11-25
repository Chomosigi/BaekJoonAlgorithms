#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<pair<int, string>> q;

int start, fin;

bool vis[10000] = { false };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> start >> fin;

		vis[start] = true;

		q.push(make_pair(start, ""));
		while (!q.empty())
		{
			int cur = q.front().first;

			string str = q.front().second;

			q.pop();

			if (cur == fin)
			{
				cout << str << "\n";
				break;
			}

			int D, S, L, R;

			D = (cur * 2) % 10000;
			if (!vis[D])
			{
				vis[D] = true;
				q.push(make_pair(D, str + "D"));
			}

			if (cur == 0)
				S = 9999;
			else
				S = cur - 1;
			if (!vis[S])
			{
				vis[S] = true;
				q.push(make_pair(S, str + "S"));
			}

			L = (cur % 1000) * 10 + (cur / 1000);
			if (!vis[L])
			{
				vis[L] = true;
				q.push(make_pair(L, str + "L"));
			}

			R = (cur / 10) + (cur % 10) * 1000;
			if (!vis[R])
			{
				vis[R] = true;
				q.push(make_pair(R, str + "R"));
			}
		}
		while (!q.empty())
			q.pop();
		memset(vis, false, sizeof(vis));
	}
}