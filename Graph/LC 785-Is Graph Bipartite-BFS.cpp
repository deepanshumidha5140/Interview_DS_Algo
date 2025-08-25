class Solution {
public:
    bool isBipartiteBFS(vector<vector<int>>& graph, vector<int>& color, int cur, int curColor){
        queue<int> que;
        que.push(cur);
        color[cur]=curColor;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int& v: graph[u]){
                if(color[v]==color[u]) return false;
                if(color[v]==-1){
                    que.push(v);
                    color[v]=1-color[u];
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!isBipartiteBFS(graph, color, i, 1)) return false;
            }
        }
        return true;
    }
};