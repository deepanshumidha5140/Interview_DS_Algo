class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> que;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!indegree[i]){
                cnt++;
                que.push(i);
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
                }
            }
        }
        if(cnt==n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto& vec: prerequisites){
            int a=vec[0], b=vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};