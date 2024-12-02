#include <iostream>

using namespace std;

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

	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	if (b < d)
	{
		swap(b, d);
		swap(a, c);
	}
	int num = a * d + b * c;
	int den = b * d;
	int div = gcd(num, den);
	cout << num / div << " " << den / div;
}