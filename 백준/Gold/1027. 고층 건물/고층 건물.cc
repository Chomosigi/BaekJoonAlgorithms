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
#define MAX -9999999999

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr;
	int* cnt;
	cnt = (int*)malloc(sizeof(int) * n);
	arr = (int*)malloc(sizeof(int) * n);

	memset(cnt, 0, sizeof(int) * n);


	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		double max_angle = MAX;
		for (int j = i + 1; j < n; j++)
		{
			double angle = (double)(arr[j] - arr[i]) / (double)(j - i);
			if (angle > max_angle)
			{
				max_angle = angle;
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < cnt[i])
			ans = cnt[i];
	}
	cout << ans;
}