
using namespace std;
#include<bits/stdc++.h>

vector<int>bellmann_ford(int n,int src,vector<vector<int>>&edges){
   //Create a dist vector
   vector<int>dist(n+1,INT_MAX);
   dist[src] = 0;

   //Relaxe all edges V-1 times

   for(int i = 0 ;i < n-1;i++){

      for(auto x : edges){
         int u = x[0] ;
         int v = x[1] ;
         int wt = x[2];
         if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
            dist[v] = dist[u] + wt;
      }
   }
   //If negative Cycle then no feasible ans as min_dist will become -INF
   //We will run our iteration one more time and agar dist[] change hua mtlb
   //ki negative cycle present hai BRO.

   for(auto x : edges){
       int u = x[0] ;
         int v = x[1] ;
         int wt = x[2];
         if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            cout<<"Negative Weight Cycle Found";
            exit(0);
            dist[v] = dist[u] + wt;
         }
   }
   return dist;
}

int main(){
   int n,m;
   cin>>n>>m;
   //edges list
   vector<vector<int>>edges;

   for(int i = 0 ; i < m ;i++){
      int u,v,wt;
      cin>>u>>v>>wt;
      edges.push_back({u,v,wt});
   }

   //Bellmann Ford Algo
   //1.Create a dist array with INF and dist[src] = 0.
   //2.Relaxe all edges V-1 times.
   //3.See for negative cycle.
   

   vector<int>dist = bellmann_ford(n,1,edges);

   for(int i =1 ; i <=n ;i++)
      cout<<"Node "<<i<<" is at distance "<<dist[i]<<endl;
}



