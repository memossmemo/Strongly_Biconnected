#include <bits/stdc++.h>
using namespace std;

class Check_Graph {        //moafak saeed
public:
  int V;
  vector<int> *vec;

  Check_Graph(int V) {
    this->V = V;
    vec = new vector<int>[V];
  }

  void addEdge(int u, int v) {                      //aya ali and shaghaf deeb
    vec[u].push_back(v);
  }

  bool isVertexStronglyBiconnected() {
    vector<bool> visited(V, false);
    int start = 0;
    if (dfsAlgorithm(start, visited, -1) != V) {
      return false;                                       // merna mohamad and meray mosa
    }
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        return false;
      }
    }
    return true;
  }

  int dfsAlgorithm(int u, vector<bool> &visited, int parent) {
    int low = u, children = 0;
    visited[u] = true;
    for (int v : vec[u]) {                                    // naya shleha and zeina aziz
      if (!visited[v]) {
        children++;
        low = min(low, dfsAlgorithm(v, visited, u));
        if (low==u&& parent !=-1) {
          return u;
        }
      } else if (v != parent) {
        low = (low < v) ? low : v;
      }
    }

    if (parent == -1 && children == 0) {           //ghadeer hagha and sleman zaher
      return u;
    }

    return low;
  }
};

int main() {         // ghafar mlhem and lujen sleman
  int V = 5;
  Check_Graph g(V);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 1);
  cout<<g.isVertexStronglyBiconnected();        //aeham daeoub and somar alptros

  if (g.isVertexStronglyBiconnected()) {
    cout << "This graph is vertex strongly biconnected." << endl;
  } else {
    cout << "This graph is not vertex strongly biconnected." << endl;
  }

  return 0;
}
