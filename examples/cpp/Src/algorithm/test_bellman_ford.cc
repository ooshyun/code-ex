/*
 * Descrption: BellmanFord (Finds the shortest path from source s to all vertices v. Detects a negative weight cycle if present.)
 * Usage: See below O(V E)
 * Source: https://github.com/dragonslayerx
 * https://github.com/qiansunn/BellmanFord
 */

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 100;
const int INF = 1e9 + 5;

struct edges {
  int u;
  int v;
  int64_t w;
  edges(int u, int v, int64_t w) : u(u), v(v), w(w) {}
};

void test_bellmanford(void) {
  int n, m;
  vector<edges> edge;

  // scanf("%d %d", &n, &m);
  // for (int i = 0; i < m; i++) {
  //   int a, b;
  //   int64_t w;
  //   scanf("%d%d%lld", &a, &b, &w);
  //   edge.push_back(edges(a, b, w));
  // }

  // example
  // n=6, m=9
  n = 6, m = 9;
  vector<edges> example_edges = {
      edges(1, 2, 6),
      edges(1, 3, 2),
      edges(2, 3, 2),
      edges(3, 5, 1),
      edges(5, 2, -4),
      edges(2, 4, 2),
      edges(5, 4, 3),
      edges(4, 6, 2),
      edges(5, 6, 4)};
  edge = example_edges;

  int parent[MAX];
  int64_t dist[MAX];
  for (int i = 0; i < n; i++) {
    parent[i] = 0;
    dist[i] = INF;
  }

  dist[0] = 0;  // distance of source node = 0
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < edge.size(); j++) {
      int u = edge[j].u;
      int v = edge[j].v;
      int64_t w = edge[j].w;
      if (dist[u] != INF) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          parent[v] = u;
        }
      }
    }
  }

  bool negCycleExists = false;
  for (int j = 0; j < edge.size(); j++) {
    int u = edge[j].u;
    int v = edge[j].v;
    int64_t w = edge[j].w;
    if (dist[v] > (dist[u] + w)) {
      negCycleExists = true;
      break;
    }
  }

  if (negCycleExists) {
    cout << "Negative Cycle Exists\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << i << "=>" << dist[i] << endl;
    }
  }
}
