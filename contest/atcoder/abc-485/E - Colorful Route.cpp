#include  <bits/stdc++.h>

using namespace std;

struct edge {
  int v, c;
};

struct node {
  int n, c, d;
};

const int MX = 200005;
vector <edge> g[MX];
set <int> cnt[MX];

int bfs(int n) {
  queue <node> q;
  q.push({1, -1, 0});

  while(!q.empty()) {
    auto p = q.front();
    q.pop();

    int u = p.n, c = p.c, d = p.d;
    
    if(cnt[u].count(c)) continue;
    if(cnt[u].size() >= 2) continue;

    cnt[u].insert(c);

    for(auto e: g[u]) {
      int v = e.v, _c = e.c;

      if(c == _c) continue;

      if(v == n) return d+1;

      q.push({v, _c, d+1});
    }
  }

  return -1;
}


int main() {
  int n, m; 
  cin >> n >> m;

  for(int i=1;i<=m;i++) {
    int u, v, c;
    cin >> u >> v >> c;

    g[u].push_back({v, c});
  }

  int ans = bfs(n);

  cout << ans << endl;
}

