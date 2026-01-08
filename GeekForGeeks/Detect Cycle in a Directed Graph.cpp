//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          unordered_map<int, vector<int>> adj;
          vector<int> indegree(V, 0);
          
          for(auto& e : edges){
              adj[e[0]].push_back(e[1]);
              indegree[e[1]]++;
          }
          
          queue<int> q;
          
          for(int i = 0 ; i < V ; i++){
              if(indegree[i] == 0)
                  q.push(i);
          }
          
          int cnt = 0;
          while(!q.empty()){
              int node = q.front();
              cnt++;
              q.pop();
              
              for(int& i : adj[node]){
                  if(indegree[i] == 1) //only one incoming node
                  {    
                      indegree[i] = 0;
                      q.push(i);
                  }
                  else
                      indegree[i]--;
              }
          }
  
          return cnt == V ? false : true;
      }
  };