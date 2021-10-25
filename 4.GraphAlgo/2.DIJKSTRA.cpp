//Dijkstra Self Brute Force and Running On Sublime
//By both Priority Queue and Set
//On Leetcode set version is giving RUNTIME ERROOR.

using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
class Graph{
   //vector<pii>*l;
   vector<vector<pii>>l;
   int V;
public:
   Graph(int V){
      this->V = V;
      //l = new vector<pii>[V];
      l = vector<vector<pii>>(V);
   }
   void addEdge(int u,int v,int w){
      l[u].push_back({v,w});
      l[v].push_back({u,w});
   }
   void printGraph(){
      for(int i = 0 ; i < V;i++){
         cout<<"Vertex is "<<i<<"  --->";
         for(auto nbrPair : l[i]){
            cout<<"("<<nbrPair.first<<","<<nbrPair.second<<")";
         }
         cout<<endl;
      }
   }
   void dijkstra(int src){

      vector<int>dist(V,INT_MAX);
      vector<bool>vis(V,false);
      dist[src] = 0;
      //set<pii>s;
      priority_queue<pii,vector<pii>,greater<pii>>pq;
      //s.insert({dist[src],src});
      pq.push({dist[src],src});

      while(!pq.empty()){
         /*auto temp = s.begin();
         s.erase(temp);
         int distTill = temp->first;
         int node = temp->second;*/
         auto temp = pq.top(); pq.pop();
         int distTill = temp.first;
         int node = temp.second;
         vis[node] = true;


         for(auto nbrPair : l[node]){

            int edgeWeight = nbrPair.second;
            int node = nbrPair.first;
            
            if(vis[node] == true) 
               continue;


            if(distTill + edgeWeight < dist[node]){


               dist[node] = distTill + edgeWeight;
               //s.insert({dist[node],node});
               pq.push({dist[node],node});
            }
         }
      }
      cout<<endl;
      for(int i = 0 ; i < V ;i++)
         cout<<"Min dist from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;

   }


};
int main(){
   Graph g(5);
   g.addEdge(0,3,10);
   g.addEdge(0,1,5);
   g.addEdge(0,2,1);
   g.addEdge(3,1,2);
   g.addEdge(1,2,2);
   g.addEdge(1,4,1);
   g.addEdge(2,4,5);
   g.printGraph();
   g.dijkstra(0);
}




    
   

   


