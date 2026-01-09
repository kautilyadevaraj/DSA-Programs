//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
class Pair{
    int x;
    int y;
    
    Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int[] shortestPath(int V, int[][] edges, int src) {
        // code here
        int[] dist = new int[V];
        Arrays.fill(dist , -1);
        
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(V);
        
        for(int i = 0 ; i < V ; i++){
            adj.add(new ArrayList<Integer>());
        }
        
        for(int[] e : edges){
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        
        Deque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(src , 0));
        dist[src] = 0;
        
        while(!q.isEmpty()){
            Pair ele = q.poll();
            int node = ele.x;
            int distance = ele.y;
            
            for(int v : adj.get(node)){
                if(dist[v] == -1){
                    q.add(new Pair(v,distance + 1));
                    dist[v] = distance + 1;
                }
            }
        }
        
        return dist;
    }
}
