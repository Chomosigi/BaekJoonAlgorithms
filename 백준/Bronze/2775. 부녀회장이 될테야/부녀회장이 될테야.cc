#include <iostream>

using namespace std;

int getNum(int x, int y)
{
	if (y == 1)
		return 1;
	else if (x == 0)
		return y;
	else
		return (getNum(x - 1, y) + getNum(x, y - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, arr[15][15] = { 0, };
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;
		cout << getNum(k, n) << "\n";
	}
}