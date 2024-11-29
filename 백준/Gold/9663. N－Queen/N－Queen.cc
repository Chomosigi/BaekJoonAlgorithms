#include <iostream>

using namespace std;

int N, ans = 0;

bool r[16] = { false };
bool diag1[30] = { false };
bool diag2[30] = { false };

void backtracking(int col)
{
	if (col == N)
	{
		ans++;
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!r[i] && !diag1[i + col] && !diag2[i - col + N])
		{
			r[i] = true;
			diag1[i + col] = true;
			diag2[i - col + N] = true;
			backtracking(col + 1);
			r[i] = false;
			diag1[i + col] = false;
			diag2[i - col + N] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	backtracking(0);
	cout << ans;
}  