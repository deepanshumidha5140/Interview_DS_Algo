class Solution {
public:
    int V;
    void BFS(vector<vector<int>>& isConnected, vector<bool>& visited, int i){
        queue<int> que;
        que.push(i);
        visited[i]=true;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int v=0; v<V; v++){
                if(!visited[v] && isConnected[u][v]==1){
                    visited[v]=true;
                    que.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        V=isConnected.size();
        vector<bool> visited(V, false);
        int res=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                BFS(isConnected, visited, i);
                res++;
            }
        }
        return res;
    }
};