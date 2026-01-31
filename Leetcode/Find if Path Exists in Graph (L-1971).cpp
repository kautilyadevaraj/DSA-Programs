class Solution {
    // bool BFS(int source , int destination , vector<vector<int>>& adj , int n){
    //     vector<bool> visited(n , false);
    //     queue<int> q;
    //     q.push(source);

    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();

    //         visited[node] = true;

    //         for(int v : adj[node]){
    //             if(!visited[v]){
    //                 q.push(v);

    //                 if(v == destination) return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    // bool DFS(int node , int destination, vector<vector<int>>& adj, vector<bool>& visited){
    //     if(node == destination)
    //         return true;

    //     visited[node] = true;

    //     for(int v : adj[node]){
    //         if(!visited[v] && DFS(v , destination , adj , visited))
    //             return true;
    //     }

    //     return false;
    // }

    int find(int i , vector<int>& parent){
        if(i == parent[i])
            return i;

        return parent[i] = find(parent[i] , parent);
    }

    void Union(int x , int y , vector<int>& parent , vector<int>& rank){
        int x_parent = find(x , parent);
        int y_parent = find(y , parent);

        if(x_parent == y_parent) return;

        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // vector<vector<int>> adj(n);

        // for(auto& e : edges){
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }

        // vector<bool> visited(n , false);
        vector<int> rank(n , 0);
        vector<int> parent(n);

        for(int i = 0 ; i < n ; i++)
            parent[i] = i;

        for(auto& e: edges){
            Union(e[0] , e[1] , parent , rank);
        }

        int source_parent = find(source , parent);
        int destination_parent = find(destination , parent);

        if(source_parent == destination_parent)
            return true;
        else
            return false;

        // return DFS(source , destination , adj , visited);
    }
};