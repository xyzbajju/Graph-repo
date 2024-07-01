// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class Solution{
 public:
  int shortestDistance(vector<vector<int>>&maze , vector<int>&start , vector<int>&dest){
	  int n = maze.size();
	  int m  =maze[0].size();
	  vector<vector<int>>dist(n ,vector<int>(m , 1e8));
	  int st_x = start[0];int st_y = start[1];  
	  int en_x = dest[0];int en_y = dest[1];  
	  dist[st_x][st_y] =0;
	  queue<pair<int,int>>q;
	  q.push({st_x , st_y});
	  int dir[5] = {-1 , 0 , 1 , 0 , -1};

	  while(!q.empty()){
		  int sz = q.size();
		  while(sz--){
			  auto [cur_x , cur_y] = q.front();q.pop();
			  for(int i =0;i<4;i++){
				 int row_dir = dir[i];
				 int col_dir = dir[i+1];
                 int dis = dist[cur_x][cur_y];
				  while( cur_x + row_dir >= 0 && cur_y + col_dir >=0 && cur_x + row_dir < n && cur_y + col_dir < m && maze[cur_x + row_dir][cur_y + col_dir] == 0){
                     dis++;
					 cur_x += row_dir;
					 cur_y += col_dir;  
				  }
				  if(dist[cur_x][cur_y] > dis){
					  dist[cur_x][cur_y] = dis;
					  q.push({cur_x , cur_y});
				  }
			  }
		  }
	  }
	  if(dist[en_x][en_y] == 1e8)return -1;
	  else return dist[en_x][en_y];
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

	int ans = HARSH.shortestDistance(maze , start, dest);
	cout<<ans<<endl;
}
