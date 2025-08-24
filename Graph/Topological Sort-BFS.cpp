class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(auto& edge: edges)
        adj[edge[0]].push_back(edge[1]);
        
        vector<int> indegree(V, 0);
        queue<int> que;
        
        for(int u=0; u<V; u++){
            for(int &v: adj[u]){
                ++indegree[v];
            }
        }
        
        for(int i=0; i<V; i++){
            if(!indegree[i])
            que.push(i);
        }
        
        vector<int> res;
        while(!que.empty()){
            int cur = que.front();
            res.push_back(cur);
            que.pop();
            
            for(auto& v: adj[cur]){
                indegree[v]--;
                if(!indegree[v]){
                    que.push(v);
                }
            }
        }
        return res;
    }
};