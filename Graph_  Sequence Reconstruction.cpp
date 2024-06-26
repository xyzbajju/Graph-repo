#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& originalSequence, vector<vector<int>>& sequences) {
        int n = originalSequence.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        for (auto& seq : sequences) {
            for (int i = 1; i < seq.size(); i++) {
                graph[seq[i - 1] - 1].push_back(seq[i] - 1);
                indegree[seq[i] - 1]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            if (q.size() > 1) return false;

            int curr = q.front();
            q.pop();

            for (auto it : graph[curr]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return true;
    }
};

int main() {
    Solution obj;
    int n, m;
    cin >> n >> m;
    vector<int> originalSequence(n);
    vector<vector<int>> sequences(m);
    
    for (int i = 0; i < n; i++) {
        cin >> originalSequence[i];
    }
    
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        sequences[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> sequences[i][j];
        }
    }
    
    bool ans = obj.sequenceReconstruction(originalSequence, sequences);
    cout << (ans ? "true" : "false") << endl;
    
    return 0;
}
