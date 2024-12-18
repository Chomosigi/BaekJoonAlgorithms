#include <iostream>
#include <vector>

#define p_long pair<long long, long long>

using namespace std;

vector<p_long> p;

long double cal(p_long a, p_long b, p_long c) {
	return (a.first * b.second) + (b.first * c.second) + (c.first * a.second)
		- (b.first * a.second) - (c.first * b.second) - (a.first * c.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long double answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long x, y;
		cin >> x >> y;
		p.push_back(make_pair(x, y));
	}

	for (int i = 1; i < n - 1; i++)
		answer += cal(p[0], p[i], p[i + 1]) / (long double)2;

	cout << fixed;
	cout.precision(1);

	cout << abs(answer);
}