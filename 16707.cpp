#include <bits/stdc++.h>
using namespace std;

#define MAX_V 2000
#define INF 1e9

struct edge {
	int to, f, c, r;
};

int N; // assign N as vertic size
vector<edge> adj[MAX_V];
int d[MAX_V];
int rve[MAX_V];
int rvi[MAX_V];
bool inq[MAX_V];
void add_edge(int fr, int to, int flow, int cost) {
	adj[fr].push_back({ to, flow, cost, (int)adj[to].size() });
	adj[to].push_back({ fr, 0, -cost, (int)adj[fr].size() - 1 });
}

int max_flow(int from, int to, int f) {
	int res = 0;
	while (f > 0) {
		queue<int> q;
		fill(d, d + MAX_V, INF);
		fill(inq, inq + MAX_V, false);
		d[from] = 0;
		q.push(from);
		inq[from] = true;
		while (!q.empty()) {
			int t = q.front(); q.pop(); inq[t] = false;
			for (int i = 0; i < adj[t].size(); i++) {
				edge &e = adj[t][i];
				if (e.f > 0 && d[t] + e.c < d[e.to]) {
					d[e.to] = d[t] + e.c;
					rve[e.to] = t;
					rvi[e.to] = i;
					if (!inq[e.to]) {
						q.push(e.to);
						inq[e.to] = true;
					}
				}
			}
		}
		if (d[to] == INF) {
			return -1;
		}
		int flow = f;
		int cost = 0;
		for (int i = to; i != from; i = rve[i]) {
			flow = min(flow, adj[rve[i]][rvi[i]].f);
			cost += adj[rve[i]][rvi[i]].c;
		}
		res += flow * cost;
		f -= flow;
		for (int i = to; i != from; i = rve[i]) {
			edge &r = adj[rve[i]][rvi[i]];
			r.f -= flow;
			adj[i][r.r].f += flow;
		}
	}
	return res;
}

int main(void)
{
	int N, M, x, y, z;

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> z;
		add_edge(x, y, 1, z);
		add_edge(y, x, 1, z);
	}

	add_edge(0, 1, 1, 0);
	add_edge(0, N, 1, 0);

	cout << max_flow(0, 2, 2);
	return 0;
}