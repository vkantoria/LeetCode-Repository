class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> in(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
                in[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);
        }
        vector<int> res;
        while(!q.empty())
        {
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(int child : adj[node])
            {
                in[child]--;
                if(in[child]==0) q.push(child);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};