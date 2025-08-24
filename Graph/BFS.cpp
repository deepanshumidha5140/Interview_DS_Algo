class Solution {
  public:
    void BFS(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, vector<int> &res){
        queue<int> que;
        que.push(u);
        visited[u]=true;
        res.push_back(u);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int v: adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v]=true;
                    res.push_back(v);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &vec) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(int u=0; u<vec.size(); u++){
            for(auto v=vec[u].begin(); v!=vec[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        vector<bool> visited(vec.size(), false);
        vector<int> res;
        BFS(adj, visited, 0, res);
        return res;
    }
};