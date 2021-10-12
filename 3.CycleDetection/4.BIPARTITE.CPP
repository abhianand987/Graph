1.USING DFS

bool dfs(vector<vector<int>>& g,int node,int vis[],int par,int color){
        vis[node] = color;
        for(int nbrs : g[node]){
            if(vis[nbrs] == 0){
                if(dfs(g,nbrs,vis,node,3-color))
                    return true;
            }
            else if(nbrs != par && color == vis[nbrs])
                return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int vis[n];
        fill(vis,vis+n,0);
        
        for(int i = 0 ; i < graph.size();i++){
            if(vis[i] == 0){
              if(dfs(graph,i,vis,-1,1))
                 return false;
        }
    }
        return true;
        
2.USING BFS

  bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>vis(n,0);
        queue<int>q;
        for(int i = 0 ; i < n;i++){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int node = q.front(); q.pop();
                    for(int nbrs : graph[node]){
                        if(!vis[nbrs]){
                            vis[nbrs] = - vis[node];
                            q.push(nbrs);
                        }
                        else if(vis[nbrs] == vis[node])
                            return false;

                    }

                }
                
        }
          
        
    }
          return true;
    }
