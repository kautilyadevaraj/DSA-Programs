class Solution {
    void DFS(int node , vector<bool>& visited , vector<vector<int>>& adj){
        visited[node] = true;

        for(int v : adj[node]){
            if(!visited[v])
                DFS(v , visited , adj);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size() , false);

        DFS(0 , visited , rooms);

        for(bool status : visited){
            if(status == false)
                return false;
        }

        return true;
    }
};