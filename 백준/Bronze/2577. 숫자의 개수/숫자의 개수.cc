#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[10];

	long long a, b, c, cal;
	cin >> a >> b >> c;

	cal = a * b * c;

	for (int i = 0; i < 10; i++)
		arr[i] = 0;

	while (cal != 0)
	{
		arr[cal % 10]++;
		cal /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\n";
}