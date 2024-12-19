#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long int arr[100000] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long int ans = 2000000000;

	int left = 0, right = n - 1;
	long long int l_ans = arr[0], r_ans = arr[n - 1];

	while (left < right)
	{
		if (ans > abs(arr[left] + arr[right]))
		{
			l_ans = arr[left];
			r_ans = arr[right];
			ans = abs(l_ans + r_ans);
		}
		if (arr[left] + arr[right] < 0)
			left++;
		else if (arr[left] + arr[right] > 0)
			right--;
		else
			break;
	}
	cout << l_ans << " " << r_ans;
}