#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
enum Color { White = 0, Grey, Black };

class Graph {
    vector<vector<int>> vec;
    vector<Color> colors;
public: Graph(int n, int m) {
    vec.resize(n);
    colors.resize(n, White);
    for (int i = 0; i < m; i++) {
        int e1 = 0;
        int e2 = 0;
        cin >> e1 >> e2;
        vec[--e1].push_back(--e2);
        vec[e2].push_back(e1);
    }
}
      void DFS(int u) {
          colors[u] = Grey;
          for (int i : vec[u]) {
              if (colors[i] == White) {
                  DFS(i);
              }
          }
          colors[u] = Black;
      }
      int Comp() {
          int n = 0;
          for (int i = 0; i < colors.size();i++) {
              if (colors[i] == White) {
                  n += 1;
                  DFS(i);
              }
          }
          return n - 1;
      }
};

int main() {
    int n = 0;
    int e = 0;
    cin >> n >> e;
    Graph graph(n, e);
    int m = graph.Comp();
    std::cout << m;
}
