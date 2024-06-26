// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

enum COLOR{
	WHITE,
	GRAY,
	BLACK,
};

class Solution{
	public:
	vector<vector<int>>buildgraph(vector<vector<int>>&edges , int n ){
		vector<vector<int>>graph(n);
        for(auto it:edges){
			graph[it[0]].push_back(it[1]);
		}
		return graph;
	}


	 bool leads_to_destination(int n, vector<vector<int>>&edges , int src , int dest ){
	   vector<vector<int>>graph = buildgraph(edges, n );
	   vector<COLOR>state(n , COLOR::WHITE);
	   return dfs(src , dest, graph ,state);
   }


	private:
	    bool dfs(int node , int dest ,   vector<vector<int>>&graph , vector<COLOR>&state){
           if(state[node] !=  COLOR::WHITE){
			   return state[node] == COLOR::BLACK;
		   }

		   if(node == dest){
			   return graph[node].empty();
		   }

		   state[node] = COLOR::GRAY;

		   for(auto it:graph[node]){
			   if(!dfs(it , dest , graph , state)){
				   return false;
			   }
		   }

		   state[node] = COLOR::BLACK;

		   return true;
		}
};
int main() {
	Solution obj;
	vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    int n = 4;
    int src = 0;
    int dest = 3;
	bool result = obj.leads_to_destination(n , edges , src , dest);
	cout<<result<<endl;
}
