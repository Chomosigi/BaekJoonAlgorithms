#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <map>

#define INF 9999999

using namespace std;

map<long, long> m;

long long fibo(long long n)
{
	if (m[n])
		return m[n];
	long long num;
	if (n % 2 == 0)
	{
		num = fibo(n / 2) * ((fibo(n / 2 + 1) + fibo(n / 2 - 1)) % 1000000007);
	}
	else
	{
		num = (fibo((n + 1) / 2) * fibo((n + 1) / 2)) % 1000000007;
		num += (fibo((n - 1) / 2) * fibo((n - 1) / 2)) % 1000000007;
	}
	m[n] = num % 1000000007;
	return m[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a;
	cin >> a;
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;

	cout << fibo(a);
}