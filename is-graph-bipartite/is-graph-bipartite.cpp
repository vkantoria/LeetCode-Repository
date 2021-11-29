class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> nodes(n, -1);
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(nodes[i] == -1)
            {
                q.push(i);
                nodes[i] = 0;
                
                while(!q.empty())
                {
                    int curr =  q.front();
                    
                    q.pop();
                    
                    for(auto v:graph[curr])
                    {
                        if(v == curr)
                             continue;
                        if(nodes[v] == -1)
                        {
                            nodes[v] = 1 - nodes[curr];
                            q.push(v);
                        }
                        else if(nodes[v] == nodes[curr])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};