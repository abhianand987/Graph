//1.Prims Algo
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
class Graph{
	//Adjacency List with weights
	int V;
	vector<pair<int,int>> *g;
public:
	Graph(int V){
		this->V = V;
		g = new vector<pair<int,int>>[V];
	}
	void addEdge(int x,int y, int wght){
		g[x].push_back({y,wght});
		g[y].push_back({x,wght});
	}
	int prims_mst(){
		//I will maintain a min heap that will store 2 things: Weight and destination node.
		priority_queue<pii,vector<pii>,greater<pii>>pq;
		
		//Another Array to store the nodes in MST set i.e, to store whether a node has been included in MST set
		bool *vis = new bool[V]{0};
		int ans = 0;
        
        //I will start from src node and push it in my priority queue
        pq.push({0,0}); //{weight,node}
        
        //Pick out the edge with min weight
        while(!pq.empty()){
        	auto best = pq.top();
        	int to = best.second , wght = best.first;

        	if(vis[to] == true){
        		///Discard the current node bcoz wo already visted hai so uspe pass hone wla dobara edge
        		// ni lunga.
        		continue;
        	}
        	else{ //otherwise take the curr node
                 ans += wght;
                 vis[to] = true;
                 //Also add the new edges from this edge(to) to the priority queue
                 for(auto nbrs : g[to]){
                 	if(vis[x.first] == false)
                 		pq.push({x.second,x.first});
                 }
        	}

        }
        return ans;   
  }}


//2.Kruskal's Algo

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
//DSU Data Structure
//Path Compression + Union By Rank

class DSU{
	int *par;
	int *rank;
public:
	DSU(int n){
		par = new int[n];
		rank = new int[n];
		for(int i = 0 ;i < n;i++){
			par[i] = -1;
			rank[i] = 1;
		}
	}
	int find(int x){
		if(par[i] == -1) return i;
		return par[i] = find(par[i]);
	}
	void unite(int x,int y){
		int s1 = find(x);
		int s2 = find(y);
		if(s1 != s2){
			if(rank[s1] < rank[s2]){
				par[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				par[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};
class Graph{
	vector<vector<int>>edgelist;
	int V;
public:
	Graph(int V){
		this->V = V;
	}
	void addEdge(int x,int y,int w){
		edgelist.push_back({w,x,y});   //w first so that sorting ho uske according
	}
	int kruskal_mst(){ 
		//Sort the edge list by weight
		DSU dsu(V);
		sort(edgelist.begin(),edgelist.end());
		int ans = 0;
		for(auto x : edgelist){
			int w = x[0];
			int u = x[1];
			int v = x[2];

			//take that edge in MST if that does not form a cycle
			if(dsu.find(u) != dsu.find(v)){
				dsu.unite(u,v);
				ans += w;
			}
		}
		return ans;
	}

};
