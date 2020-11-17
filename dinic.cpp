const int N = 500;
const int M = 10000;

int n, m;
struct Edge {
  int v, u, c, f = 0;
  Edge() {}
  Edge(int v, int u, int c) : v(v), u(u), c(c) {}
  int cf() { return c - f; }
} e[2 * M];
vector<int> g[N];
int s, t;

int df;

int dist[N];

bool bfs() {
  queue<int> q;
  q.push(s);
  fill(dist, dist + n, -1);
  dist[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i : g[v]) {
      if (e[i].cf() >= df && dist[e[i].u] == -1) {
        dist[e[i].u] = dist[v] + 1;
        q.push(e[i].u);
      }
    }
  }
  return dist[t] != -1;
}

int ptr[N];

bool dfs(int v) {
  if (v == t) {
    return true;
  }
  for (; ptr[v] < g[v].size(); ++ptr[v]) {
    int i = g[v][ptr[v]];
    if (dist[v] + 1 == dist[e[i].u] && e[i].cf() >= df && dfs(e[i].u)) {
      e[i].f += df;
      e[i ^ 1].f -= df;
      return true;
    }
  }
  return false;
}

void dinic() {
  const int K = 30;
  for (df = 1 << K; df >= 1; df >>= 1) {
    while (bfs()) {
      fill(ptr, ptr + N, 0);
      while (dfs(s)) {
      }
    }
  }
}
