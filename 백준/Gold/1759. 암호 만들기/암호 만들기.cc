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

void dfs(char* arr, char* pw, int idx, int cnt, int n, int m, bool vow, int con) {
	if (cnt == n)
	{
		if (!vow || con < 2)
			return;
		for (int i = 0; i < n; i++)
			cout << pw[i];
		cout << '\n';
		return;
	}

	pw[cnt] = arr[idx];
	if (idx < m)
	{
		if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
			dfs(arr, pw, idx + 1, cnt + 1, n, m, true, con);
		else
			dfs(arr, pw, idx + 1, cnt + 1, n, m, vow, con + 1);
		dfs(arr, pw, idx + 1, cnt, n, m, vow, con);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	char* arr;
	char* pw;
	arr = (char*)malloc(sizeof(char) * m);
	pw = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < m; i++)
		cin >> arr[i];

	sort(arr, arr + m);

	dfs(arr, pw, 0, 0, n, m, false, 0);

	free(arr);
	free(pw);

	return 0;
}