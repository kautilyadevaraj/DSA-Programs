class Solution {
    void traverse(int startNode, vector<vector<int>>& adj, int* visited, vector<vector<int>>& ans){
        //bfs traversal
        queue<int> q;
        vector<int> component;
        q.push(startNode);
        visited[startNode] = 1;

        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
                int node = q.front();
                component.push_back(node);
                q.pop();
                
                for(int i : adj[node]){
                    if(!visited[i]){
                        visited[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
        
        ans.push_back(component);
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> adj(V);
        
        for(int i = 0 ; i < edges.size() ; i++){
            //undirected
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int visited[V] = {0};
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i])
                traverse(i, adj, visited, ans);
        }
        
        return ans;
    }
};
