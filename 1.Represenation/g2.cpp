#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string name;
	list<string> nbrs;
	Node(string name){
		this->name = name;
	}
};

class Graph{
	
	//What All Nodes Are there and
	//HashMap(key : string, value : Node*)
	unordered_map<string , Node* > mp;
public:
	Graph(vector<string> cities){
		for(auto city : cities)
			mp[city] = new Node(city);
	}
	void addEdge(string x , string y, bool undir = false){
		//mp[x] ek pointer hai jo x ke node ko point 
		//kr rha so when we use ptr to access properties
		//we use -> operator 
         mp[x]->nbrs.push_back(y);
		if(undir)
			mp[y]->nbrs.push_back(x);
	}
	void printList(){
		for(auto cityPair : mp){
			string cityName = cityPair.first;
			cout<<cityName<<"-->";
			Node* node = cityPair.second;
			for(auto x : node->nbrs)
				cout<<x<<",";
			cout<<endl;

		}


	}

}; 

int main(){

    vector<string> cities = {"NewYork","London","Paris","Delhi"};
	Graph G(cities);
	G.addEdge("Delhi","London");
	G.addEdge("NewYork","London");
	G.addEdge("Delhi","Paris");
	G.addEdge("Paris","NewYork");
	G.printList();
	


}
