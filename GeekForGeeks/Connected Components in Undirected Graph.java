class Solution {
    void traverse(int startNode, ArrayList<ArrayList<Integer>> adj, boolean[] visited, ArrayList<ArrayList<Integer>> ans){
        //bfs traversal
        Queue<Integer> q = new ArrayDeque<>();
        ArrayList<Integer> component = new ArrayList<>();

        q.add(startNode);
        visited[startNode] = true;

        
        while(!q.isEmpty()){

            int node = q.poll();
            component.add(node);
                
            for(int i : adj.get(node)){
                if(!visited[i]){
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
        
        ans.add(component);
    }
    public ArrayList<ArrayList<Integer>> getComponents(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(V);
        
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        
        for(int i = 0 ; i < edges.length ; i++){
            //undirected
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        
        boolean[] visited = new boolean[V];
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i])
                traverse(i, adj, visited, ans);
        }
        
        return ans;
    }
}