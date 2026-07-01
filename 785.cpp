#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {

        if (color[i] != -1)
            continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neigh : graph[node]) {

                if (color[neigh] == -1) {
                    color[neigh] = 1 - color[node];
                    q.push(neigh);
                }
                else if (color[neigh] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    // Example 1 (Bipartite)
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (isBipartite(graph))
        cout << "Graph is Bipartite";
    else
        cout << "Graph is NOT Bipartite";

    return 0;
}