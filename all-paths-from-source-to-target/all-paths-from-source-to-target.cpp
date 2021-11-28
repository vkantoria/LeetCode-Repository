class Solution {   
public:
     vector<vector<int>> res;
    
   void DfsUtil(int v, vector<int> adj[], vector<int> path, int dest)
    {
        path.push_back(v);
        
        if(v == dest)
        {
            res.push_back(path);
            return;
        }
        for(auto r : adj[v])
        {
            DfsUtil(r, adj, path, dest);
        }
    }
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
        int n = graph.size();
        vector<int> path;
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
                {
                   adj[i].push_back(graph[i][j]); 
                }
        } 
        
        DfsUtil(0, adj, path, n-1);
        return res;
    }
};