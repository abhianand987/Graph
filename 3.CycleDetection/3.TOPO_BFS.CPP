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
			l[y].push_back(x);
	}
	void printGraph(){
		for(int i = 0 ; i < V;i++){
			cout<<i<<"--->";
			for(auto x : l[i])
				cout<<x<<",";
			cout<<endl;}
	}
	void topological_sort(){
		vector<int>inDegree(V,0);
		//Iterate over all the edges to find indegree
		for(int i = 0 ; i < V;i++){
			for(auto nbrs : l[i])
				inDegree[nbrs]++;
		}
		queue<int>q;
		//Push all the nodes having 0 indegree BRO
		for(int i = 0 ; i < V;i++){
			if(inDegree[i] == 0)
				q.push(i);
		}
		while(!q.empty()){
			int node = q.front(); q.pop(); cout<<node<<" ";
			//Iterate over nbrs of this node and decrease their indegree by 1.
			for(auto nbrs : l[node]){
				inDegree[nbrs]--;
				if(inDegree[nbrs] == 0)
					q.push(nbrs);
			}
		}
	}
	//Can also be used to detect Cycle bcoz when we have cycle there will not
	//be any vertex with indegree 0 so we maintain count of vertices with 
	//indegree == 0 and agar ye #vertices se kam aaya mtlb cycle.
	bool isCycleDG(){
		vector<int>inDegree(V,0);
		//Iterate over all the edges to find indegree
		for(int i = 0 ; i < V;i++){
			for(auto nbrs : l[i])
				inDegree[nbrs]++;
		}
		queue<int>q;
		//Push all the nodes having 0 indegree BRO
		for(int i = 0 ; i < V;i++){
			if(inDegree[i] == 0)
				q.push(i);
		}
		int count = 0;
		while(!q.empty()){
			int node = q.front(); q.pop(); cout<<node<<" ";
			//Iterate over nbrs of this node and decrease their indegree by 1.
			for(auto nbrs : l[node]){
				inDegree[nbrs]--;
				if(inDegree[nbrs] == 0)
					q.push(nbrs);
			}
			count++;
		}
		return count != V;

	}
    


};



int main(){

	Graph g(6);
	cout<<"Hi";
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(4,5);
	g.addEdge(6,5);
	g.addEdge(2,3);
	g.topological_sort();

} 
