#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
#define endl '\n'
#define pb push_back
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define trace(x) cout<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x,y,z) cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl


class Graph{
	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];

	}
	void addEdge(int i ,int j, bool undir = true){
		l[i].push_back(j);
		if(undir = true)
			l[j].push_back(i);}
	void printGraph(){
		//Iterate over all V rows
		for(int i = 0 ; i < V;i++){
			cout<<i<<"--->";
			for(int node : l[i])
				cout<<node<<",";
			cout<<endl;
		}
	}	
};
int main(){
	Graph G(5);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,3);
	G.addEdge(1,4);
	G.printGraph();
	//printGraph();

}