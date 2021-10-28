///1.WITHOUT DP
using namespace std;
#include<bits/stdc++.h>

int tsp(vector<vector<int>> &dist,int n,int curr_city,int city_mask){
   //base case
   if(city_mask == (1<<n)-1){
      //return the cost from that curr city to source/original city i,e, 0.
      return dist[curr_city][0];
   }
  

   //otherwise try all possible options BRO i.e, 0--->1,2,3 ki edges niklegi tree
   int ans = INT_MAX;
   for(int choice = 0 ; choice < n ;choice++){
      //need to check if choice city is visted or not so we need to check ki kya wo city bit is OFF
      if((( city_mask ) & ( 1 << choice ) ) == 0){
         int subproblm = dist[curr_city][choice] + tsp(dist,n,choice,city_mask | (1<<choice) );
         ans = min(ans,subproblm);
      }
   }
   return ans;

}

int main(){
  //There is an edge from every vertex mere BHAI.
  vector<vector<int>> dist ={
       {0,20,42,25},
       {20,0,30,34},
       {42,30,0,10},
       {25,34,10,0}
  };
  memset(dp,-1,sizeof(dp));

  cout<<tsp(dist,4,0,1);
}

///2.With DP only 2 line changes

using namespace std;
#include<bits/stdc++.h>

int tsp(vector<vector<int>> &dist,int n,int curr_city,int city_mask,vector<vector<int>>&dp){
   //base case
   if(city_mask == (1<<n)-1){
      //return the cost from that curr city to source/original city i,e, 0.
      return dist[curr_city][0];
   }
   if(dp[curr_city][city_mask] != -1)
      return dp[curr_city][city_mask];

   //otherwise try all possible options BRO i.e, 0--->1,2,3 ki edges niklegi tree
   int ans = INT_MAX;
   for(int choice = 0 ; choice < n ;choice++){
      //need to check if choice city is visted or not so we need to check ki kya wo city bit is OFF
      if((( city_mask ) & ( 1 << choice ) ) == 0){
         int subproblm = dist[curr_city][choice] + tsp(dist,n,choice,city_mask | (1<<choice),dp);
         ans = min(ans,subproblm);
      }
   }
   return dp[curr_city][city_mask] = ans;

}

int main(){
  //There is an edge from every vertex mere BHAI.
  vector<vector<int>> dist ={
       {0,20,42,25},
       {20,0,30,34},
       {42,30,0,10},
       {25,34,10,0}
  };
  int n = dist.size();

  vector<vector<int>>dp(n,vector<int>((1<<n),-1));

  cout<<tsp(dist,n,0,1,dp);
}
