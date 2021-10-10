#include<bits/stdc++.h>
using namespace std;



class Graph{
	int V;
	vector<int> *l;
	
public:
	Graph(int v){
		V = v;
		l = new vector<int>[V];
	}
	void addEdge(int x,int y,bool undir=true){
		l[x].push_back(y);
		if(undir)
			l[y].push_back(x);}
	void printGraph(){
		for(int i = 0 ; i < V;i++){
			cout<<i<<"--->";
			for(auto x : l[i])
				cout<<x<<",";
			cout<<endl;}
		}
	
	bool dfsCycle(int src,int par,vector<bool>&vis){
		vis[src] = true;
		for(auto nbrs : l[src]){
			if(!vis[nbrs]){
				if(dfsCycle(nbrs,src,vis))
					return true;
			}
      //This nbr is visited and it is not the parent of current node in the current DFS call.
			else if(vis[nbrs] && nbrs != par)  
        //The main idea is if we visit a node again which is not parent then its cycle in UG == UNDIRECTED GRAPH.
				return true;
		}
		return false;

	}	
	bool isCycle(){
		vector<bool>vis(V,false);
		return dfsCycle(0,-1,vis);

	}	


};



int main(){
	Graph g(7);
	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.printGraph();
	//g.bfs(1,3);
	//g.dfs(1);
	cout<<g.isCycle();






 


} 
