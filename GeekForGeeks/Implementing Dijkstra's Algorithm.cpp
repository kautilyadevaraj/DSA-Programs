class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
          vector<vector<pair<int,int>>> adj(V);
          
          for(auto& e: edges){
              adj[e[0]].push_back({e[1],e[2]});
              adj[e[1]].push_back({e[0],e[2]});
          }
          
          vector<int> result(V,INT_MAX);
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          
          pq.push({0,src});
          result[src] = 0;
          
          while(!pq.empty()){
              pair<int,int> ele = pq.top();
              pq.pop();
              int node = ele.second;
              int dist = ele.first;
              
              if (dist > result[node]) continue;
              
              for(auto& it : adj[node]){
                  int newDist = dist + it.second;
                  if(newDist < result[it.first]){
                      result[it.first] = newDist;
                      pq.push({newDist,it.first});
                  }
              }
          }
          
          return result;
      }
  };