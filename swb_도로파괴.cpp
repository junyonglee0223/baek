#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

static const long long INF = (1LL << 60);

/*
    도로 정보
    - id    : 도로 ID
    - u, v  : u -> v 방향 도로
    - w     : 소요 시간
    - alive : 현재 존재하는 도로인지 여부
*/
struct Edge {
    int id;
    int u, v, w;
    bool alive;
};

static int gN;                              // 도시 개수
static vector<Edge> edges;                  // 모든 도로 저장
static vector<vector<int>> outEdges;        // 정방향 인접 리스트: outEdges[u] = u에서 나가는 도로 index들
static vector<vector<int>> inEdges;         // 역방향 인접 리스트: inEdges[v] = v로 들어오는 도로 index들
static unordered_map<int, int> idToIdx;     // 도로 ID -> edges 내부 index

/*
    다익스트라 우선순위 큐에 넣을 상태
    dist가 작은 것이 먼저 나오도록 operator<를 반대로 정의
*/
struct Node {
    long long dist;
    int v;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

/*
    s에서 시작하는 정방향 다익스트라

    dist[x]    : s -> x 최단거리
    parentV[x] : 최단경로 트리에서 x 직전 정점
    parentE[x] : 최단경로 트리에서 x로 들어오는 도로 index

    이 정보로 나중에 s -> t의 실제 최단경로 하나를 복원할 수 있다.
*/
static void dijkstraForward(int s, vector<long long>& dist, vector<int>& parentV, vector<int>& parentE) {
    dist.assign(gN, INF);
    parentV.assign(gN, -1);
    parentE.assign(gN, -1);

    priority_queue<Node> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        // 이미 더 좋은 거리로 갱신된 뒤에 나온 오래된 상태는 무시
        if (cur.dist != dist[cur.v]) continue;

        // cur.v에서 나가는 살아있는 도로들 확인
        for (int ei : outEdges[cur.v]) {
            const Edge& e = edges[ei];
            if (!e.alive) continue;

            long long nd = cur.dist + e.w;
            if (nd < dist[e.v]) {
                dist[e.v] = nd;
                parentV[e.v] = cur.v;
                parentE[e.v] = ei;
                pq.push({nd, e.v});
            }
        }
    }
}

/*
    t를 기준으로 역방향 다익스트라

    실제 그래프에서 x -> t 최단거리를 구하기 위해
    역방향 그래프(inEdges)를 사용한다.

    dist[x]   : x -> t 최단거리
    nextV[x]  : 최단경로 트리에서 x 다음 정점
    nextE[x]  : 최단경로 트리에서 x -> nextV[x]로 가는 도로 index

    즉, forward에서 parent를 기록했다면,
    reverse에서는 "다음에 어디로 가면 t로 최단인가"를 기록하는 셈이다.
*/
static void dijkstraReverse(int t, vector<long long>& dist, vector<int>& nextV, vector<int>& nextE) {
    dist.assign(gN, INF);
    nextV.assign(gN, -1);
    nextE.assign(gN, -1);

    priority_queue<Node> pq;
    dist[t] = 0;
    pq.push({0, t});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.dist != dist[cur.v]) continue;

        // cur.v로 들어오는 간선을 역으로 따라가면
        // 원래 그래프에서 그 간선의 시작점에서 cur.v로 올 수 있는 것
        for (int ei : inEdges[cur.v]) {
            const Edge& e = edges[ei];
            if (!e.alive) continue;

            long long nd = cur.dist + e.w;
            if (nd < dist[e.u]) {
                dist[e.u] = nd;
                nextV[e.u] = cur.v;
                nextE[e.u] = ei;
                pq.push({nd, e.u});
            }
        }
    }
}

/*
    구간 최소값 갱신 + 한 점 질의용 세그먼트 트리

    여기서는 다음 역할로 사용한다.

    최단경로 P의 각 간선을 1번, 2번, ..., k번 간선이라 하자.
    어떤 "우회 후보 경로"가 P의 l번~r번 간선을 한 번에 우회할 수 있다면
    그 후보 경로 길이를 [l, r] 구간에 반영한다.

    이후 i번 간선을 끊었을 때 가능한 후보 경로들의 최소값이
    바로 i 위치에 대한 질의 결과가 된다.

    즉:
    - update(l, r, candidateDistance)
    - query(i) = i번 경로 간선을 대체할 수 있는 후보들 중 최소 거리
*/
struct SegTree {
    int n;
    vector<long long> lazy;

    void init(int sz) {
        n = sz;
        lazy.assign(4 * (n + 1), INF);
    }

    /*
        [l, r] 구간에 val 후보를 넣는다.
        이 문제에서는 "최소 대체 거리"가 필요하므로 min으로 누적
    */
    void update(int node, int nl, int nr, int l, int r, long long val) {
        if (r < nl || nr < l) return;

        if (l <= nl && nr <= r) {
            if (val < lazy[node]) lazy[node] = val;
            return;
        }

        int mid = (nl + nr) >> 1;
        update(node << 1, nl, mid, l, r, val);
        update(node << 1 | 1, mid + 1, nr, l, r, val);
    }

    /*
        idx 위치에 대해 루트부터 내려오며 누적된 최소값을 전달
    */
    long long query(int node, int nl, int nr, int idx, long long acc) {
        if (lazy[node] < acc) acc = lazy[node];
        if (nl == nr) return acc;

        int mid = (nl + nr) >> 1;
        if (idx <= mid) return query(node << 1, nl, mid, idx, acc);
        return query(node << 1 | 1, mid + 1, nr, idx, acc);
    }
};

void init(int N, int K, int mId[], int sCity[], int eCity[], int mTime[]) {
    gN = N;

    edges.clear();
    edges.reserve(K + 1600);

    outEdges.assign(N, {});
    inEdges.assign(N, {});
    idToIdx.clear();

    for (int i = 0; i < K; i++) {
        int idx = (int)edges.size();

        edges.push_back({mId[i], sCity[i], eCity[i], mTime[i], true});
        outEdges[sCity[i]].push_back(idx);
        inEdges[eCity[i]].push_back(idx);
        idToIdx[mId[i]] = idx;
    }
}

void add(int mId, int sCity, int eCity, int mTime) {
    int idx = (int)edges.size();

    edges.push_back({mId, sCity, eCity, mTime, true});
    outEdges[sCity].push_back(idx);
    inEdges[eCity].push_back(idx);
    idToIdx[mId] = idx;
}

void remove(int mId) {
    int idx = idToIdx[mId];
    edges[idx].alive = false;
    idToIdx.erase(mId);
}

int calculate(int sCity, int eCity) {
    vector<long long> distS, distT;
    vector<int> parentV, parentE;
    vector<int> nextV, nextE;

    // 1) sCity 기준 최단거리 계산
    dijkstraForward(sCity, distS, parentV, parentE);

    // 처음부터 도달 불가능하면 문제 조건상 -1
    if (distS[eCity] >= INF / 2) return -1;

    // 2) eCity 기준 역방향 최단거리 계산
    dijkstraReverse(eCity, distT, nextV, nextE);

    long long base = distS[eCity]; // 원래 최단거리

    /*
        3) parent 정보를 이용해 sCity -> eCity 최단경로 하나를 복원한다.

        pathV : 경로 위 정점들
                예: v0, v1, v2, ..., vk
        pathE : 경로 위 간선들
                예: e1(v0->v1), e2(v1->v2), ..., ek(v{k-1}->vk)

        pathE의 크기를 k라 하면
        "i번 간선"이라는 표현은 pathE[i-1]을 의미하게 된다.
    */
    vector<int> pathV;
    vector<int> pathE;
    {
        vector<int> revV;
        vector<int> revE;

        int cur = eCity;
        revV.push_back(cur);

        while (cur != sCity) {
            int pe = parentE[cur];
            int pv = parentV[cur];

            revE.push_back(pe);
            revV.push_back(pv);
            cur = pv;
        }

        reverse(revV.begin(), revV.end());
        reverse(revE.begin(), revE.end());

        pathV = revV;
        pathE = revE;
    }

    int k = (int)pathE.size(); // 최단경로 위 간선 수

    /*
        pos[x] = x가 복원한 최단경로 pathV의 몇 번째 정점인지
        경로 위에 없으면 -1

        예를 들어
        pathV = [s, a, b, c, t] 라면
        pos[s]=0, pos[a]=1, pos[b]=2, pos[c]=3, pos[t]=4
    */
    vector<int> pos(gN, -1);
    for (int i = 0; i <= k; i++) {
        pos[pathV[i]] = i;
    }

    /*
        아래에서는 reverse 다익스트라로 얻은 nextV/nextE를
        "복원한 실제 path"와 일치시키기 위해 path 위 정점들에 대해서 강제로 맞춰준다.

        이유:
        dist는 같더라도 최단경로가 여러 개면 reverse 트리 구조가
        우리가 복원한 path와 조금 다를 수 있다.
        이후 label 전파를 안정적으로 하려면 path 기준이 명확해야 한다.
    */
    for (int i = 0; i < k; i++) {
        int u = pathV[i];
        int v = pathV[i + 1];
        nextV[u] = v;
        nextE[u] = pathE[i];
    }

    /*
        4) 최단경로 트리(parentV)와
           역최단경로 트리(nextV)를 자식 리스트 형태로 만든다.

        childS: s에서 내려가는 최단경로 트리
        childT: t로 향하는 역최단경로 트리
    */
    vector<vector<int>> childS(gN), childT(gN);

    for (int v = 0; v < gN; v++) {
        if (v != sCity && parentV[v] != -1) {
            childS[parentV[v]].push_back(v);
        }
        if (v != eCity && nextV[v] != -1) {
            childT[nextV[v]].push_back(v);
        }
    }

    /*
        labelS[x]:
        s에서 x로 가는 최단경로 트리를 따라 내려왔을 때
        path 위에서 "마지막으로 지나친 정점 index"

        예:
        path가 s(0) - a(1) - b(2) - c(3) - t(4)이고,
        어떤 x가 path의 b에서 갈라져 나온 서브트리에 있으면
        labelS[x] = 2

        즉 x에 도달하기 전까지 path 상 어디까지 따라왔는가를 뜻한다.
    */
    vector<int> labelS(gN, -1);

    /*
        labelT[x]:
        x에서 t로 가는 역최단경로 트리를 따라갈 때
        path 위에서 "처음 합류하는 정점 index"

        예:
        어떤 x에서 t로 가는 최단경로가 path의 c로 먼저 합류한다면
        labelT[x] = 3
    */
    vector<int> labelT(gN, -1);

    // labelS 계산: s 기준 최단경로 트리를 BFS/DFS처럼 따라가며 전파
    {
        queue<int> q;
        labelS[sCity] = 0;
        q.push(sCity);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : childS[u]) {
                // 자식이 path 위 정점이면 그 자체 index가 새로운 기준
                if (pos[v] != -1) labelS[v] = pos[v];
                // path 밖 정점이면 부모의 기준을 그대로 이어받음
                else labelS[v] = labelS[u];

                q.push(v);
            }
        }
    }

    // labelT 계산: t로 향하는 역최단경로 트리를 따라가며 전파
    {
        queue<int> q;
        labelT[eCity] = k;
        q.push(eCity);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : childT[u]) {
                // 자식이 path 위 정점이면 그 정점 index가 합류 지점
                if (pos[v] != -1) labelT[v] = pos[v];
                // path 밖이면 부모와 같은 합류 지점 사용
                else labelT[v] = labelT[u];

                q.push(v);
            }
        }
    }

    /*
        5) path 위 간선인지 표시

        중요한 사실:
        path 위에 없는 간선을 제거해도
        우리가 복원한 path 자체는 그대로 살아있으므로 최단거리 증가가 없다.

        따라서 "파괴해서 지연"을 일으킬 수 있는 후보는
        path 위 간선들만 보면 된다.
    */
    vector<char> isPathEdge(edges.size(), 0);
    for (int ei : pathE) isPathEdge[ei] = 1;

    /*
        6) path 위 i번 간선을 우회할 수 있는 모든 후보 경로를 interval로 세그트리에 반영한다.

        어떤 path 밖 간선 e: u -> v를 생각하자.
        만약
          - s -> u 최단경로는 path를 labelS[u]까지 따라간 뒤 갈라지고
          - v -> t 최단경로는 path의 labelT[v]에서 다시 합류한다면

        이 후보 경로
          s -> ... -> u -> v -> ... -> t
        는
          path의 (labelS[u]+1)번 간선부터 labelT[v]번 간선까지
        전부 우회할 수 있다.

        따라서 그 구간 [l, r]에 대해 후보 거리 distS[u] + w + distT[v]를 넣는다.
    */
    SegTree seg;
    seg.init(k);

    for (int ei = 0; ei < (int)edges.size(); ei++) {
        const Edge& e = edges[ei];
        if (!e.alive) continue;

        // path 위 간선은 "우회 간선 후보"가 아님
        if (isPathEdge[ei]) continue;

        // s -> u 또는 v -> t가 불가능하면 후보 경로 자체가 불가능
        if (distS[e.u] >= INF / 2 || distT[e.v] >= INF / 2) continue;

        if (labelS[e.u] == -1 || labelT[e.v] == -1) continue;

        int l = labelS[e.u] + 1;
        int r = labelT[e.v];

        /*
            l <= r 일 때만 실제로 path 구간을 우회하는 의미가 있다.

            예를 들어
            path index 기준으로
            u는 path의 1번 정점 근처에서 갈라지고,
            v는 path의 4번 정점 근처에서 합류하면
            2~4번 간선을 우회 가능하다는 뜻이다.
        */
        if (l <= r) {
            long long cand = distS[e.u] + e.w + distT[e.v];
            seg.update(1, 1, k, l, r, cand);
        }
    }

    /*
        7) path의 각 간선을 하나씩 끊었을 때의 최단거리 계산

        i번 경로 간선을 끊었을 때:
        - query(i)가 INF이면 대체 경로가 없으므로 도달 불가능 -> -1
        - 아니면 그 값이 "i번 간선을 제거했을 때의 최단거리"

        문제는 "하나의 간선을 골라서 지연 시간을 최대화"하는 것이므로
        각 i에 대해 (대체거리 - 원래거리)의 최댓값을 구한다.
    */
    long long ans = 0;

    for (int i = 1; i <= k; i++) {
        long long repl = seg.query(1, 1, k, i, INF);

        // path의 i번 간선을 끊었을 때 우회 경로가 전혀 없으면
        // 문제 조건상 -1 반환
        if (repl >= INF / 2) return -1;

        ans = max(ans, repl - base);
    }

    return (int)ans;
}