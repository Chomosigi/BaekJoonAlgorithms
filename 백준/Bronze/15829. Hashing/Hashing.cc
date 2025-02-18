#include <iostream>

using namespace std;

int main() {
	int l, ans = 0;
	cin >> l;
	string s;
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--)
		ans = (s[i] - 'a' + 1) + ans * 31;
	cout << ans;
}