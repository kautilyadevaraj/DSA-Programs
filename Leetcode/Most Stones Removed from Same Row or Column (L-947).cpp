class Solution {
    int find(int i , vector<int>& parent){
        if(i == parent[i])
            return i;
        
        return parent[i] = find(parent[i] , parent);
    }

    void Union(int x_parent , int y_parent , vector<int>& parent , vector<int>& size){
        if(x_parent == y_parent) return;

        if(size[x_parent] > size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else{
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> size(n , 1);
        vector<int> parent(n);

        for(int i = 0 ; i < n ; i++)
            parent[i] = i;

        int groups = n;

        for(int x = 0 ; x < n ; x++){
            for(int y = x + 1 ; y < n ; y++){
                if(stones[x][0] == stones[y][0] || stones[x][1] == stones[y][1]){
                    int x_parent = find(x , parent);
                    int y_parent = find(y , parent);

                    if(x_parent == y_parent) continue;

                    Union(x_parent , y_parent , parent , size);
                    groups--;
                }
            }
        }

        return n - groups;
    }
};