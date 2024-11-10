#include <iostream>
#include <queue>
using namespace std;

int arr[101][101][101];
int M, N, H;

int mX[6] = {-1, 0, 0, 1, 0, 0};
int mY[6] = {0, -1, 0, 0, 1, 0};
int mZ[6] = {0, 0, -1, 0, 0, 1};

queue <pair <pair <int, int>, int>> q;

void bfs() {
    while(!q.empty())
    {
        int pX = q.front().first.first;
        int pY = q.front().first.second;
        int pZ = q.front().second;

        int dist = arr[pX][pY][pZ];
        q.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int tX = pX + mX[i];
            int tY = pY + mY[i];
            int tZ = pZ + mZ[i];
            
            if(tX < 0 || tY < 0 || tZ < 0 || tX >= H || tY >= N || tZ >= M || arr[tX][tY][tZ] != 0) continue;
            arr[tX][tY][tZ] =  dist + 1;
            q.push(make_pair(make_pair(tX, tY), tZ));
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;

    int temp;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                cin >> temp;
                arr[i][j][k] = temp;
                if(temp == 1)
                    q.push(make_pair(make_pair(i, j), k));
            }
        }
    }

    bfs();

    int answer = 0;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                if(arr[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, arr[i][j][k] - 1);
            }
        }
    }
    cout << answer;
}