//Dijkstra Self Brute Force and Running On Sublime
//By both Priority Queue and Set
//On Leetcode set version is giving RUNTIME ERROOR.
//Idea -1 Slight Optimization
	// DIJKSTRA-1
	void Dijkstra(long src, vector<pair<long, long>> adj[], vector<long>&dist)
	{
		priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
		pq.push({0, src});
		minDistanceFromSrcTo[src] = 0;
		long u, v, wt, currdist;
		while (!pq.empty()) {
			u = pq.top().second;
			currdist = pq.top().first;
			pq.pop();
			// below line in Dijkstra becomes game changer
			// because if for any pair in priority_queue pq
			// minDistanceFromSrcTo[u] < dist
			// then shortest path passing from this u is already processed
			// so no need to go below for() loop for time consumption
			if (dist[u] < dist) continue; //Good Optimization
         
         
			for (auto it : adj[u]) {
				v = it.first;
				wt = it.second;
				if (dist[u] + wt < dist[v]) {
					dist[v] = wt + dist[u];
					pq.push({dist[v], v});
				}
			}
		}
	}
// DIJKSTRA-2 More Optimizations
void Dijkstra(long src, vector<pair<long, long>> adj[], vector<long>&dist)
	{
		priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
		pq.push({0, src});
		minDistanceFromSrcTo[src] = 0;
		long u, v, wt, currdist;
		while (!pq.empty()) {
			u = pq.top().second;
			currdist = pq.top().first;
			pq.pop();
         
         vis[u] = true; //More Optimization
         
			
			if (dist[u] < dist) continue;
			for (auto it : adj[u]) {
				v = it.first;
            
            if(vis[v]) continue;
            
				wt = it.second;
				if (dist[u] + wt < dist[v]) {
					dist[v] = wt + dist[u];
					pq.push({dist[v], v});
				}
			}
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
         int u = temp.second;
         vis[node] = true;


         for(auto nbrPair : l[node]){

            int edgeWeight = nbrPair.second;
            int v = nbrPair.first;
            
            if(vis[v] == true) 
               continue;


            if(dist[u] + edgeWeight < dist[v]){


               dist[v] = dist[u] + edgeWeight;
               //s.insert({dist[node],node});
               pq.push({dist[v],v});
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




    
   

   


