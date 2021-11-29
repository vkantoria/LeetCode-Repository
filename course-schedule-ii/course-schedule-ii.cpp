class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> adj[numCourses];
        vector<int> ans;
        
        for(auto i:pre)
        {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto i:adj[curr])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
            
        }
        vector<int> res;
        
        return ans.size() == numCourses?ans:res;
        
    }
};