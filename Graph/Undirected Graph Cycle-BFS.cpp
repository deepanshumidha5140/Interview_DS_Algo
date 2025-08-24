class Solution {
  public:
    bool isCycleBFS(unordered_map<int, vector<int>> adj, vector<bool> visited, int parent, int u){
        queue<pair<int, int>> que;
        que.push({u, parent});
        visited[u]=true;
        while(!que.empty()){
            pair<int, int> P=que.front();
            int source=P.first;
            int parent=P.second;
            que.pop();
            for(int &v: adj[source]){
                if(visited[v]==false){
                    visited[v]=true;
                    que.push({v, source});
                }
                else if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleBFS(adj, visited, -1, i)){
                return true;
            }
        }
        return false;
    }
};