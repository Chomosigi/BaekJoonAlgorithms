#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

void binary_search(int len, int target)
{
	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (target == arr[mid])
		{
			cout << 1 << " ";
			return;
		}
		if (target < arr[mid])
			high = mid - 1;
		else if (target > arr[mid])
			low = mid + 1;
	}
	cout << 0 << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		binary_search(T, n);
	}
}