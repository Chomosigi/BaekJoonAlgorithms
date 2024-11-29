#include <iostream>
#include <algorithm>

using namespace std;

int N;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);
		cout << a * b / gcd(a, b) << "\n";
	}
}  