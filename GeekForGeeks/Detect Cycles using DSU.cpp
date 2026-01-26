//https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1

class Solution {
    int find(int i , vector<int>& parent){
        if(i == parent[i])
            return i;
            
        return parent[i] = find(parent[i] , parent);
    }
    
    bool Union(int x , int y , vector<int>& rank, vector<int>& parent){
        int x_parent = find(x , parent);
        int y_parent = find(y , parent);
        
        if(x_parent == y_parent)
            return true;
        
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
            
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        
        else{
            rank[y_parent]++;
            parent[x_parent] = y_parent;
        }
         
        return false;   
    }
  public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        vector<int> rank(V , 0);
        vector<int> parent(V);
        
        for(int i = 0 ; i < V ; i++)
            parent[i] = i;
        
        for(int u = 0 ; u < V ; u++){
            for(int v : adj[u]){
                if(u < v && Union(u , v , rank , parent))
                    return true;
            }
        }
        
        return false;
    }
};