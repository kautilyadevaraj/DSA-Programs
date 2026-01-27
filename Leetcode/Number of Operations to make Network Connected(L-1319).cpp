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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int networks = n;
        int extra = 0;
        vector<int> rank(n , 0);
        vector<int> parent(n);

        for(int i = 0 ; i < n ; i++)
            parent[i] = i;

        for(auto& e : connections){
            int u = e[0];
            int v = e[1];

            int u_parent = find(u , parent);
            int v_parent = find(v , parent);

            if(u_parent != v_parent){
                Union(u_parent , v_parent , parent , rank);
                networks--;
            }

            else
                extra++;
        }

        if(extra >= networks - 1)
            return networks - 1;

        return -1;
    }
};