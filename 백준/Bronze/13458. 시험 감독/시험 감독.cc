#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <iomanip>
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
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int m, s;
	long long ans = 0;
	cin >> m >> s;
	for (int i = 0; i < n; i++)
	{
		int stu = arr[i];
		stu -= m;
		if (stu <= 0)
			ans++;
		else if (stu % s != 0)
			ans += (2 + stu / s);
		else if (stu != 0 && stu % s == 0)
			ans += (1 + stu / s);
	}
	cout << ans;
	free(arr);
	return 0;
}