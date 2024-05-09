
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


void test_dijkstra(void) {

    // n=5, m=8
    // 0, 1, 7
    // 0, 2, 4
    // 0, 3, 6
    // 0, 4, 1
    // 2, 1, 2
    // 2, 3, 5
    // 3, 1, 3
    // 4, 3, 1

}