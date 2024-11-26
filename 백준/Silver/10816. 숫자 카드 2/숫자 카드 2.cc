#include <iostream>
#include <map>

using namespace std;

map<int, int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (arr.find(num) != arr.end())
			arr[num]++;
		else
			arr[num] = 1;
	}

	cin >> N;

	for (int j = 0; j < N; j++)
	{
		cin >> num;
		if (arr.find(num) != arr.end())
			cout << arr[num] << " ";
		else
			cout << "0 ";
	}
}