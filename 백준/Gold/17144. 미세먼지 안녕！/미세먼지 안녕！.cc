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

int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};

void airfresh(int** arr, int r, int c, pair<int, int> p)
{
	int x = p.first;
	int y = p.second;

	int** temp = new int* [r];
	for (int i = 0; i < r; i++)
		temp[i] = new int[c];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			temp[i][j] = -2;
	}

	for (int i = 1; i <= x - 1; i++)
	{
		temp[i][0] = arr[i - 1][0];
		temp[i - 1][c - 1] = arr[i][c - 1];
	}
	for (int i = 1; i < c; i++)
	{
		temp[0][i - 1] = arr[0][i];
		temp[x - 1][i] = arr[x - 1][i - 1];
	}
	for (int i = x + 1; i < r; i++)
	{
		temp[i - 1][0] = arr[i][0];
		temp[i][c - 1] = arr[i - 1][c - 1];
	}
	for (int i = 1; i < c; i++)
	{
		temp[x][i] = arr[x][i - 1];
		temp[r - 1][i - 1] = arr[r - 1][i];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (temp[i][j] != -2)
			{
				if (arr[i][j] != -1)
				{
					if (temp[i][j] == -1)
						arr[i][j] = 0;
					else
						arr[i][j] = temp[i][j];
				}
			}
		}
	}

	for (int i = 0; i < r; i++)
		delete[] temp[i];
	delete[] temp;
}

void spread(int** arr, int r, int c)
{
	int** temp = new int* [r];
	for (int i = 0; i < r; i++)
		temp[i] = new int[c];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			temp[i][j] = 0;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] > 0)
			{
				int sp_amount = arr[i][j] / 5;
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + mx[k];
					int ny = j + my[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == -1)
						continue;
					temp[nx][ny] += sp_amount;
					cnt++;
				}
				arr[i][j] -= sp_amount * cnt;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(arr[i][j] != -1)
				arr[i][j] += temp[i][j];
		}
	}

	for (int i = 0; i < r; i++)
		delete[] temp[i];
	delete[] temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, t, ans = 0;

	cin >> r >> c >> t;

	pair<int, int> p;

	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[c];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				p = { i, j };
		}
	}

	for (int i = 0; i < t; i++)
	{
		spread(arr, r, c);
		airfresh(arr, r, c, p);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] != -1)
				ans += arr[i][j];
		}
	}

	cout << ans;

	for (int i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
    
    return 0;
}