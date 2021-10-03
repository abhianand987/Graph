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
	void bfs(int source,int dest = -1){
		
		queue<int>q;
		bool *visited = new bool[V]{0};   //To mark visited
		int *dis = new int[V]{0};        //To maintain distance
		int *par = new int[V];         //To trace out the path we maintain Parent Array.
		for(int i =0; i < V;i++) 
			par[i] = -1;


		q.push(source);
		visited[source] = true;
		par[source] = source;
		dis[source] = 0;

		
		while(!q.empty()){
			//Print the curr node
			int curr = q.front(); q.pop();
			//cout<<curr<<" ";
			//Push the nghbrs of curr node inside queue if they are not visited
       for(auto neighbrs : l[curr]){
			  	if(!visited[neighbrs]){
					     q.push(neighbrs);
					     visited[neighbrs] = true;
					     par[neighbrs] = curr;
					     dis[neighbrs] = dis[curr] + 1;  // curr is the parent of neighbrs
				}
			}
		}
		//Print the shortest distance
		for(int i = 0 ; i < V ;i++)
			cout<<"The shortest distance from source to node "<<i<<" is "<<dis[i]<<endl;
		//Print the shortes path
		if(dest != -1){
			while(dest != source){
				cout<<dest<<"--->";
				dest = par[dest];
			}
			cout<<source;
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
	//g.printGraph();
	g.bfs(1,3);
}
