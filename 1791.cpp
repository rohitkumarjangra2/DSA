#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // Create adjacency list
        vector<vector<int>> graph(n);

        // Build adjacency list
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main() {

    int n = 6;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {3,5},
        {5,4},
        {4,3}
    };

    int source = 0;
    int destination = 5;

    Solution obj;

    if (obj.validPath(n, edges, source, destination))
        cout << "Path Exists";
    else
        cout << "Path Does Not Exist";

    return 0;
}