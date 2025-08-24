class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, vector<int>& visited, vector<int>& inRecursion, int u){
        visited[u]=true;
        inRecursion[u]=true;
        for(int& v: adj[u]){
            if(!visited[v] && isCycleDFS(adj, visited, inRecursion, v))
            return true;
            else if(inRecursion[v])
            return true;
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto& P: prerequisites) adj[P[1]].push_back(P[0]);
        vector<int> visited(numCourses, false);
        vector<int> inRecursion(numCourses, false);
        for(int i=0; i<numCourses; i++){
            if(!visited[i] && isCycleDFS(adj, visited, inRecursion, i)){
                return false;
            }
        }
        return true;
    }
};