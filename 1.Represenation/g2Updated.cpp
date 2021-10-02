#include<bits/stdc++.h>
using namespace std;



class Graph{
	
	//What All Nodes Are there and
	//HashMap(key : string, value : vector<neigbors>)
	unordered_map<string , vector<string> > mp;
public:
	Graph(vector<string> cities){
		for(auto x : cities){
			//Initializing Empty Vector To every city of MAP is very IMP mere BHAU.
			//Or else when u will add jiski koi neigbor ni hai wo ni aygi map me BC.

			vector<string>v;
			mp[x] = v;
		}
		
	}
	void addEdge(string x , string y, bool undir = false){
        mp[x].push_back(y);
		if(undir)
			mp[y].push_back(x);
	}
	void printList(){
		for(auto cityPair : mp){
			string cityName = cityPair.first;
			cout<<cityName<<"-->";
		
			for(auto x : cityPair.second)
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
