#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
  //n nodes and m edges
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	        OR
	vector<vector<int>>G(n);
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	return 0;
}
