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

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int arr[26];
		for (int i = 0; i < 26; i++)
			arr[i] = 0;
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
		char prev = s[0];
		bool flag = true;
		for (int i = 1; i < s.length(); i++)
		{
			if (arr[s[i] - 'a'] == 0 || prev == s[i])
			{
				prev = s[i];
				arr[s[i] - 'a']++;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
	}
	cout << ans;
}