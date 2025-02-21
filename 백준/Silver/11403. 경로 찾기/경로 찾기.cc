#include <iostream>
#include <queue>

using namespace std;

int main() {
	int dijkstra[100], n, way[100][100];
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> way[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dijkstra[j] = 0;
		q.push(i);
		while (!q.empty())
		{
			int idx = q.front();
			q.pop();
			for (int j = 0; j < n; j++)
			{
				if (way[idx][j] == 1 && dijkstra[j] == 0)
				{
					dijkstra[j] = 1;
					q.push(j);
				}
			}
		}
		for (int j = 0; j < n; j++)
			cout << dijkstra[j] << " ";
		cout << "\n";
	}
}