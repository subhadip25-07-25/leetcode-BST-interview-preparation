class Solution {
public:
    vector<vector<int>> graph;
    void makegraph(int src, int dest) {
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    bool dfs(int src, int dest, vector<bool>& visited) {
        if (src == dest) {
            return true;
        }
        visited[src] = true;
        for (auto neighbour : graph[src]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, dest, visited)) {
                    return true;
                };
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        graph.resize(n);
        for (auto& ele : edges) {
            makegraph(ele[0], ele[1]);
        }
        vector<bool>visited( n ,false);
        return dfs( source , destination ,visited );
    }
};