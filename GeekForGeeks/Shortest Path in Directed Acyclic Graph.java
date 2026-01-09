// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public void DFS(int node, ArrayList<ArrayList<Pair>> adj, Deque<Integer> st, boolean[] visited) {
        visited[node] = true;

        for (Pair v : adj.get(node)) {
            if (visited[v.x] == false)
                DFS(v.x, adj, st, visited);
        }

        st.push(node);
    }

    public int[] shortestPath(int V, int E, int[][] edges) {
        int[] dist = new int[V];
        Arrays.fill(dist, -1);

        ArrayList<ArrayList<Pair>> adj = new ArrayList<>(V);

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<Pair>());
        }

        for (int[] e : edges) {
            adj.get(e[0]).add(new Pair(e[1], e[2]));
        }

        Deque<Integer> st = new ArrayDeque<>();
        boolean[] visited = new boolean[V];

        DFS(0, adj, st, visited);

        dist[0] = 0;

        while (!st.isEmpty()) {
            int node = st.pop();
            for (Pair v : adj.get(node)) {
                if (dist[v.x] == -1 || dist[node] + v.y < dist[v.x]) {
                    dist[v.x] = dist[node] + v.y;
                }
            }
        }

        return dist;
    }
}