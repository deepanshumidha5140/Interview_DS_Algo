class Solution {
  public:
    bool isCycleDFS(unordered_map<int, vector<int>> adj, vector<bool>& visited, vector<bool>& inRecursion, int u){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int &v: adj[u]){
            if(!visited[v] && isCycleDFS(adj, visited, inRecursion, v))
            return true;
            else if(inRecursion[v]==true)
            return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, visited, inRecursion, i)){
                return true;
            }
        }
        return false;
    }
};