class Solution {
    int find(int i , vector<int>& parent){
        if(i == parent[i])
            return i;

        return parent[i] = find(parent[i] , parent);
    }

    void Union(int x_parent , int y_parent , vector<int>& parent , vector<int>& rank){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n , 0);
        vector<int> parent(n);

        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
        
        int provinces = n;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 0 || i == j) continue;
                int i_parent = find(i , parent);
                int j_parent = find(j , parent);

                if(i_parent == j_parent) continue;

                provinces--;

                Union(i_parent , j_parent , parent , rank);
            }
        }

        return provinces;
    }
};