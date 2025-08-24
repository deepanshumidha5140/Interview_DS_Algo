class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        for(auto& edge: edges)
        adj[edge[0]].push_back(edge[1]);
        
        queue<int> que;
        vector<int> indegree(V, 0);
        int cnt=0;
        
        for(int u=0; u<V; u++){
            for(int& v: adj[u]){
                indegree[v]++;
            }
        }
        
        for(int i=0; i<V; i++){
            if(!indegree[i]){
                que.push(i);
                cnt++;
            }
        }
        
        while(!que.empty()){
            int u=que.front();
            que.pop();
            
            for(int& v: adj[u]){
                indegree[v]--;
                if(!indegree[v]){
                    que.push(v);
                    cnt++;
                }
            }
        }
        
        if(cnt==V) return false;
        return true;
    }
};