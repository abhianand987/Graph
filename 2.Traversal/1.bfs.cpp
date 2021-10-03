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
			l[y].push_back(x);
	}
	void printGraph(){
		for(int i = 0 ; i < V;i++){
			cout<<i<<"--->";
			for(auto x : l[i])
				cout<<x<<",";
			cout<<endl;}
		}
	void bfs(int source){
		
		queue<int>q;
		bool *visited = new bool[26]{0};

    //Put the source inside queue and mark it visited
		q.push(source);
		visited[source] = true;

		
		while(!q.empty()){
			//Print the curr node
			int curr = q.front(); q.pop();
			cout<<curr<<" ";
			
			//Push the nghbrs of curr node inside queue if they are not visited
      for(auto neighbrs : l[curr])
				     if(!visited[neighbrs])
					        visited[neighbrs] = true , q.push(neighbrs);
			
		}

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
	g.bfs(1);
}
