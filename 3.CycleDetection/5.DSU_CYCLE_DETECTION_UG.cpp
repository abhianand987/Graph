#include<bits/stdc++.h>
using namespace std;

//Detecting Cycle in UG using DSU

class Graph{
	int V;
	vector<pair<int,int>> list;   //Edge List Representation
	
public: 
	Graph(int V){       ///Graph Constructor
		this->V = V;
	}
	void addEdge(int u ,int v){
		list.push_back({u,v});
	}
	
	//Find fn returns the root node i.e, master parent bhai there is difference b/w parent and root.
	//ROOT == MASTER PARENT      AND     PARENT == IMMEDIATE PARENT.
	//par[] wla array is immediate parent array.
	//Initailly every par[i] is -1 as saare nodes independent/disjoint sets hai
	
	int find_set(int i , int par[]){
		if(par[i] == -1) 
			return i;
		return find_set(par[i],par);
	}

    //Basically union(a,b) == JOINING/LINKING ROOT OF A AND B ONLW WHEN DONO ALAG SETS ME HAI.

	void union_set(int a, int b, int par[]){
		int s1 = find_set(a,par);
		int s2 = find_set(b,par);
		if(s1 != s2)
			par[s1] = s2;
	}	
    
    bool contains_cycle(){
    	//DSU Logic To Detect Cycle in UG
    	int *par = new int[V];
    	for(int i = 0 ; i < V;i++) par[i] = -1;

    	for(auto edge : list){
    		int u = edge.first;
    		int v = edge.second;
    		int s1 = find_set(u,par);
    		int s2 = find_set(v,par);
    		if(s1 != s2){
    	       par[s1] = s2;
    		}
    		else{
    			cout<<"Same parents of "<<u<<" and "<<v<<" are "<<s1<<"  "<<s2<<endl;
    			return true;
    		}
    	}
    	return false;

    }	
};
int main(){

	Graph g(4);
	//cout<<"Hi";
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	cout<<g.contains_cycle();
	

} 
