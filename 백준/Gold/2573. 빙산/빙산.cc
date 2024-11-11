#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[300][300];
bool visit[300][300];
int move_x[4] = { 1, -1, 0, 0 };
int move_y[4] = { 0, 0, 1, -1 };

void meltCheck()
{
    int temp[300][300] = { 0 };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0) continue;
            int melt = 0;
            for (int k = 0; k < 4; k++)
            {
                int src_x = i + move_x[k];
                int src_y = j + move_y[k];
                if (src_x < 0 || src_y < 0 || src_x >= N || src_y >= M) continue;
                if (arr[src_x][src_y] == 0)
                    melt++;
            }
            temp[i][j] = arr[i][j] - melt;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp[i][j] <= 0)
                arr[i][j] = 0;
            else
                arr[i][j] = temp[i][j];
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int src_x = q.front().first;
        int src_y = q.front().second;
        q.pop();
        

        for (int i = 0; i < 4; i++)
        {
            int nx = src_x + move_x[i];
            int ny = src_y + move_y[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (arr[nx][ny] != 0 && !visit[nx][ny])
                {
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    int year = 0;

    while (true)
    {
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] != 0 && !visit[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        memset(visit, false, sizeof(visit));

        if (cnt == 0)
        {
            cout << 0;
            break;
        }

        else if (cnt >= 2)
        {
            cout << year;
            break;
        }

        year++;

        meltCheck();
    }
}