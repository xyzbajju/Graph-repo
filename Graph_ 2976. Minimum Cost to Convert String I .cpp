#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimum_Cost(string source, string result, vector<int>& original, vector<int>& changed, vector<int>& cost) {
        vector<vector<int>> graph(26, vector<int>(26, 1e9));

        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            graph[original[i]][changed[i]] = cost[i];
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == result[i]) continue;
            else {
                if (graph[source[i] - 'a'][result[i] - 'a'] == 1e9) return -1;
                ans += graph[source[i] - 'a'][result[i] - 'a'];
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;

    string source, result;
    cin >> source >> result;

    vector<int> original(n), changed(n), cost(n);
    for (int i = 0; i < n; i++) {
        char o;
        cin >> o;
        original[i] = o - 'a';
    }
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        changed[i] = c - 'a';
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    long long ans = obj.minimum_Cost(source, result, original, changed, cost);

    cout << ans << endl;

    return 0;
}
