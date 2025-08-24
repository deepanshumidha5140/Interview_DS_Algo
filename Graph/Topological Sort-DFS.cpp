class Solution {
  public:
    void DFS(unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& st, int u){
        visited[u]=true;
        for(int& v: adj[u]){
            if(!visited[v])
                DFS(adj, visited, st, v);
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto& edge: edges)
        adj[edge[0]].push_back(edge[1]);
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!visited[i])
            DFS(adj, visited, st, i);
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};