#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define INF 9999999

using namespace std;

vector<pair<int, int>> root[801];

int dist[801];

int N, E;	// N은 끝지점, E는 간선의 개수

void bfs(int n)
{
	memset(dist, INF, sizeof(int) * (N + 1));	// dist 배열 초기화(다익스트라 쓰기위함)
	priority_queue<pair<int, int>> pq;	// 우선순위 큐 선언
	pq.push({ 0, n });					// 특정 지점을 시작으로하는 pq 집어넣기
	dist[n] = 0;						// 기준점 0 설정
	while (!pq.empty())					// 흔한 bfs
	{
		int tot_dist = -pq.top().first;
		// 해당 지점까지 오기까지의 거리(-를 안넣어주면 vector<...>, greater<...> 넣어줘야함
		int node = pq.top().second;		// 탐색중인 노드 번호
		pq.pop();						// 탐색했으면 큐 삭제해줘야지

		if (dist[node] < tot_dist)		// 이미 진행된 값에 비해 너무 높음(진행할 가치 없음)
			continue;
		for (int i = 0; i < root[node].size(); i++)			// 해당 노드의 모든 길 탐색
		{
			int nnode = root[node][i].first;				// 다음 진행 노드 번호
			int ncost = root[node][i].second + tot_dist;	// 해당 지점까지의 비용

			if (dist[nnode] > ncost)						
				// 이미 진행한 값이 현재 탐색한 값보다 작으면 할 필요가 없음
			{
				pq.push({ -ncost, nnode });
				dist[nnode] = ncost;
			}
		}
	}
}

int main() {
	cin >> N >> E;

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		root[a].push_back({ b, c });
		root[b].push_back({ a, c });
	}
	int u, v;	// 중간에 거쳐야 하는 두 지점
	cin >> u >> v;
	
	bfs(1); // 시작점이 1인 bfs
	int near_u = dist[u];	// 1에서 u 까지의 거리값(1 -> u -> v -> N에서 1->u의 값에 해당)
	int near_v = dist[v];	// 1에서 v 까지의 거리값(1 -> v -> u -> N에서 1->v의 값에 해당)

	bfs(u);					// 시작점이 u인 bfs
	int uv = dist[v];		// u에서 v 까지의 거리(방향은 양방향이기에 u에서 가든 v에서 가든 의미없음)
	int uN = dist[N];		// u에서 N 까지의 거리(1 -> v -> u -> N에서 u->N의 값에 해당)

	bfs(v);
	int vN = dist[N];		// v에서 N 까지의 거리값(1 -> u -> v -> N에서 v->N의 값에 해당)

	if (near_u >= INF || near_v >= INF || uv >= INF || uN >= INF || vN >= INF)
		// 어느 구간이든 갈 수 없는 경우(해당하는 길이 존재하지 않는 경우 -1 출력)
		cout << -1;

	else
	{
		int utov = near_u + vN + uv;	// 1 -> u -> v -> N의 거리값
		int vtou = near_v + uN + uv;	// 1 -> v -> u -> N의 거리값
		cout << min(utov, vtou);		// 둘 중 최소값 출력
	}
}