class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int> indegree){
        queue<int> que;
        vector<int> res;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!indegree[i]){
                cnt++;
                que.push(i);
                res.push_back(i);
            }
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int& v: adj[u]){
                indegree[v]--;
                if(!indegree[v]){
                    cnt++;
                    que.push(v);
                    res.push_back(v);
                }
            }
        }
        if(cnt==n) return res;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto& P: prerequisites){
            adj[P[1]].push_back(P[0]);
            indegree[P[0]]++;
        }
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};