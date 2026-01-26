class Solution {
    int find(int i , vector<int>& parent){
        if(parent[i] == i)
            return i;

        return parent[i] = find(parent[i] , parent);
    }

    void Union(int x , int y , vector<int>& rank, vector<int>& parent){
        int x_parent = find(x , parent);
        int y_parent = find(y , parent);
        
        if(x_parent == y_parent)
            return;
        
        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
            
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        
        else{
            rank[y_parent]++;
            parent[x_parent] = y_parent;
        } 
    }

public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26 , 0);

        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
        }

        for(string s : equations){
            if(s[1] == '!')
                continue;

            Union(s[0] - 'a' , s[3] - 'a' , rank , parent);
        }

        for(string s : equations){
            if(s[1] == '=')
                continue;

            int u = s[0] - 'a';
            int v = s[3] - 'a';

            int u_parent = find(u , parent);
            int v_parent = find(v , parent);

            if(u_parent == v_parent)
                return false;
        }

        return true;
    }
};