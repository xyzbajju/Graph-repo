#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, int node) {
        int n = graph.size();
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, node});
        dist[node] = 0;
        
        while (!pq.empty()) {
            auto [curr_dist, nod] = pq.top(); pq.pop();
            if (curr_dist > dist[nod]) continue;
            for (auto &[neighbor, weight] : graph[nod]) {
                long long new_dist = curr_dist + weight;
                if (new_dist < dist[neighbor]) {
                    dist[neighbor] = new_dist;
                    pq.push({new_dist, neighbor});
                }
            }
        }
        return dist;  
    }

    long long flightCost(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph_forward(n);
        vector<vector<pair<int, int>>> graph_backward(n);

        for (auto &it : edges) {
            graph_forward[it[0] - 1].push_back({it[1] - 1, it[2]});
            graph_backward[it[1] - 1].push_back({it[0] - 1, it[2]});
        }

        vector<long long> dist_forward = dijkstra(graph_forward, 0);
        vector<long long> dist_backward = dijkstra(graph_backward, n - 1);

        long long ans = LLONG_MAX;

        for (auto &it : edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int cost = it[2];
            if (dist_forward[u] == LLONG_MAX || dist_backward[v] == LLONG_MAX) continue;
            long long x = dist_forward[u] + dist_backward[v] + cost / 2;
            ans = min(ans, x);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i][0] = a;
        edges[i][1] = b;
        edges[i][2] = c;
    }

    cout << sol.flightCost(n, m, edges) << endl;
    return 0;
}
