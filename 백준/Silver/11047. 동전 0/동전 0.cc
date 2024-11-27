#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, money, cur = 0, ans = 0;

	cin >> N >> money;

	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;
		s.push(coin);
	}

	while (cur != money)
	{
		int high = s.top();
		if (money - cur < high)
			s.pop();
		else
		{
			cur += high;
			ans++;
		}
	}
	cout << ans;
}