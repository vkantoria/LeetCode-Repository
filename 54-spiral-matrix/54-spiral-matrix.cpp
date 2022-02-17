class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mo) {
        
        int m = mo.size();
        int n = mo[0].size();
        vector<int> ans;
        
        int top = 0, right = n-1;
        int down = m-1, left = 0; 
        int count = m*n;
        
        while(top<=down && left<=right)
        {
            for(int i=top;i<=right;i++)
            {
                ans.push_back(mo[top][i]);
                //count--;
            }
            top++;
            if(top>down)
                break;
            
            for(int i=top;i<=down;i++)
            {
                ans.push_back(mo[i][right]);
                   //count--;
            }
            right--;
            if(right<left)
                break;
            
            for(int i=right;i>=left;i--)
            {
                ans.push_back(mo[down][i]);
                   //count--;
            }
            down--;
            
            
            for(int i=down;i>=top;i--)
            {
                ans.push_back(mo[i][left]);
                   //count--;
            }
            left++;
            
        }
        return ans;
    }
};