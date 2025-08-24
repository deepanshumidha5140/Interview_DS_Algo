class Solution {
  public:
    void DFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, vector<int> &res){
        if(visited[u]) return;
        visited[u]=true;
        res.push_back(u);
        for(int v: adj[u]){
            if(!visited[v]) DFS(adj, visited, v, res);
        }
    }
    vector<int> dfs(vector<vector<int>>& vec) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(int u=0; u<vec.size(); u++){
            for(auto v=vec[u].begin(); v!=vec[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        vector<int> res;
        vector<bool> visited(vec.size(), false);
        DFS(adj, visited, 0, res);
        return res;
    }
};