class Solution {
public:
    bool hasCycle=false;

    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion, stack<int>& st){
        visited[u]=true;
        inRecursion[u]=true;
        for(int& v: adj[u]){
            if(inRecursion[v]){
                hasCycle=true;
                return;
            }
            if(!visited[v]){
                DFS(adj, v, visited, inRecursion, st);
            }
        }
        st.push(u);
        inRecursion[u]=false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        stack<int> st;
        hasCycle=false;

        for(auto& vec: prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                DFS(adj, i, visited, inRecursion, st);
            }
        }

        if(hasCycle)
        return {};
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};