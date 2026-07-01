class Solution {
public:

    vector<int> topoSortBFS(vector<int> adj[],int n){
        vector<int>indegree(n);
        for(int i = 0 ; i<n ; i++){
            for(auto ele : adj[i]){
                indegree[ele]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int y = q.front();
            q.pop();
            topo.push_back(y);
            for(auto ele : adj[y]){
                indegree[ele]--;
                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }
        reverse(topo.begin(),topo.end());  
        return topo;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        for(int i = 0 ; i<pre.size() ; i++){
            auto ele = pre[i];
            adj[ele[0]].push_back(ele[1]);
        }
        vector<int>topo = topoSortBFS(adj,numCourses);

        if(topo.size()!=numCourses){
            return {};
        }
        return topo;
    }
};