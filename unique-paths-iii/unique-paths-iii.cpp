class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j, int &ans, int m, int n, int &count, int x, int y)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1 || visited[i][j] == 1) return;
        visited[i][j] = 1;
        count--;
        if(i ==x && j ==y)
        {
            if(count == 0)
            {
                ans++;
            }
            
        }
        dfs(grid,visited, i, j-1, ans, m, n, count,x,y);
        dfs(grid,visited,i-1,j,ans,m,n, count,x,y);
        dfs(grid,visited,i,j+1,ans,m,n, count,x,y);
        dfs(grid,visited,i+1,j,ans,m,n,count,x,y);
        count ++;
        visited[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0, ans = 0;
        
        pair<int,int> start, end;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != -1)
                {
                  count++;
                    if(grid[i][j] == 1)
                        start = make_pair(i, j);
                    if(grid[i][j] == 2)
                        end = make_pair(i,j);
                }
            }
        }
        
        dfs(grid, visited, start.first, start.second, ans, m, n, count, end.first,end.second);  
        return ans;
    }
};