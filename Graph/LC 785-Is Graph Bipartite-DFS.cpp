class Solution {
public:
    bool isBipartiteDFS(vector<vector<int>>& graph, vector<int>& color, int cur, int curColor){
        color[cur]=curColor;
        for(int& v: graph[cur]){
            if(color[v]==curColor) return false;
            if(color[v]==-1){
                int vColor=1-curColor;
                if(isBipartiteDFS(graph, color, v, vColor)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!isBipartiteDFS(graph, color, i, 1)) return false;
            }
        }
        return true;
    }
};