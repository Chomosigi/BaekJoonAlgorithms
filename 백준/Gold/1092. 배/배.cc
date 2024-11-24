#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> box;
	vector<int> crane;


	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		crane.push_back(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		box.push_back(num);
	}

	int cnt = 0;

	sort(box.begin(), box.end(), greater<>());
	sort(crane.begin(), crane.end(), greater<>());

	if (box[0] > crane[0])
	{
		cout << -1;
		return 0;
	}

	while (!box.empty())
	{
		cnt++;
		for (int i = 0; i < crane.size(); i++)
		{
			for (int j = 0; j < box.size(); j++)
			{
				if (crane[i] >= box[j])
				{
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}

	cout << cnt;
}