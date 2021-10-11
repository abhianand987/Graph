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
	void addEdge(int x,int y,bool undir=false){
		l[x].push_back(y);
		if(undir)
			l[y].push_back(x);}

	bool dfsDG(int node,vector<bool>&vis,vector<bool>&stack){
    //return true if backedge is present
		vis[node]= true;
		stack[node]=true;
		//Do some work at a node
    for(auto nbrs : l[node]){
			if(!vis[nbrs]){
				if(dfsDG(nbrs,vis,stack))
					return true;
			}
      else if(vis[nbrs] && stack[nbrs])
      {
				return true;
			}
		}
    //Going back from a node.
    stack[node] = false;
		return false;
	}
	bool isCycleDG(){
		vector<bool>vis(V,false);
		vector<bool>stack(V,false);
		for(int i = 0 ; i < V;i++){
			if(!vis[i]){
				if(dfsDG(i,vis,stack))
					return true;
			}
		}
		return false;
	}	


};



int main(){
	Graph g(7);
	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(5,3);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.printGraph();
	//g.bfs(1,3);
	//g.dfs(1);
	//cout<<g.isCycleUG();
	cout<<g.isCycleDG();







 


} 
