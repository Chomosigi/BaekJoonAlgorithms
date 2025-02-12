#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

void bt(int before, long long num)
{
	v.push_back(num);
	for (int i = before - 1; i >= 0; i--)
		bt(i, num * 10 + i);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
		bt(i, i);
	sort(v.begin(), v.end());
	if (v.size() <= (n - 1))
		cout << -1;
	else
		cout << v[n - 1];
	return 0;
}