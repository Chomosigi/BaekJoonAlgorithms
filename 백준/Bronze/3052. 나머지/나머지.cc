#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

#define INF 9999999

using namespace std;


int main() {
	int arr[42] = { 0 };
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		int n;
		cin >> n;
		if (arr[n % 42] == 0)
		{
			arr[n % 42]++;
			ans++;
		}
	}
	cout << ans;
}