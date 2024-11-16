#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, max = 0;
	int arr[10001] = { 0 };
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int N;
		cin >> N;
		arr[N]++;
		if (max < N)
			max = N;
	}

	for (int i = 1; i <= max; i++)
	{
		while (arr[i] != 0)
		{
			cout << i << "\n";
			arr[i]--;
		}
	}
	return 0;
}