#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for (auto& it : edges) {
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }

        vector<int> parent(n, -1);
        vector<int> proOrder;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            proOrder.push_back(node);
            for (auto it : graph[node]) {
                graph[it].erase(node);
                parent[node] = it;

                if (graph[it].size() == 1) {
                    q.push(it);
                }
            }
            graph[node].clear();
        }

        vector<int> dist(n, 0);
        for (int i = proOrder.size() - 1; i >= 0; i--) {
            if (parent[proOrder[i]] != -1) {
                dist[proOrder[i]] = dist[parent[proOrder[i]]] + 1;
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {4, 5}};
    int n = 6;

    vector<int> result = sol.distanceToCycle(n, edges);
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

}
