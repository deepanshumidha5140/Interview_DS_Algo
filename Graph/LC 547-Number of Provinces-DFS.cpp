class Solution {
public:
    int V;
    void DFS(vector<vector<int>>& isConnected, vector<bool>& visited, int u){
        visited[u]=true;
        for(int v=0; v<V; v++){
             if(!visited[v] && isConnected[u][v]){
                DFS(isConnected, visited, v);
             }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        V=isConnected.size();
        vector<bool> visited(V, false);
        int res=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                res++;
                DFS(isConnected, visited, i);
            }
        }
        return res;
    }
};