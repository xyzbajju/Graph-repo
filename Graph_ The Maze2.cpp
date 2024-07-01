#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e8));
        int st_x = start[0], st_y = start[1];
        int en_x = dest[0], en_y = dest[1];
        dist[st_x][st_y] = 0;
        queue<pair<int, int>> q;
        q.push({st_x, st_y});
        int dir[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [cur_x, cur_y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int row_dir = dir[i];
                    int col_dir = dir[i + 1];
                    int new_x = cur_x, new_y = cur_y;
                    int dis = dist[cur_x][cur_y];

                    while (new_x + row_dir >= 0 && new_y + col_dir >= 0 &&
                           new_x + row_dir < n && new_y + col_dir < m &&
                           maze[new_x + row_dir][new_y + col_dir] == 0) {
                        dis++;
                        new_x += row_dir;
                        new_y += col_dir;
                    }

                    if (dist[new_x][new_y] > dis) {
                        dist[new_x][new_y] = dis;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return dist[en_x][en_y] == 1e8 ? -1 : dist[en_x][en_y];
    }
};

int main() {
    Solution HARSH;
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    vector<int> start = {0, 4};
    vector<int> dest = {4, 4};

    int ans = HARSH.shortestDistance(maze, start, dest);
    cout << ans << endl;

    return 0;
}
