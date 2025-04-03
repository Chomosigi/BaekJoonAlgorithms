#include <iostream>

#define INF 9999999
#define MAX -9999999999

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, l, flag = false;;
	cin >> n >> l;

	while (l <= 100 && !flag)
	{
		if ((2 * n + l - l * l) % (2 * l) == 0)
		{
			long long int start = (2 * n + l - l * l) / (2 * l);
			if (start >= 0)
			{
				for (int i = 0; i < l; i++)
					cout << start + i << " ";
				flag = true;
			}
		}
		l++;
	}
	if (!flag)
		cout << -1;
}