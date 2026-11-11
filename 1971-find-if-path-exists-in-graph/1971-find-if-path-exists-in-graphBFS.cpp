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
    bool bfs ( int src , int dest , vector<bool>& visited){
        queue<int>qu;
        qu.push( src);
        visited[src]= true;
        while( !qu.empty()){
            auto node = qu.front();
            if( node == dest )return true;
            qu.pop();
              for (auto neighbour : graph[node]) {
                   if (!visited[neighbour]) {
                       qu.push( neighbour);
                       visited[neighbour]= true;
                   }
              }
        }
        return false ;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        graph.resize(n);
        for (auto& ele : edges) {
            makegraph(ele[0], ele[1]);
        }
        vector<bool>visited( n ,false);
       // return dfs( source , destination ,visited );
       return bfs ( source , destination ,visited );
    }
};