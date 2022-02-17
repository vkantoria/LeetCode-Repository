class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        int row_up = 0, row_down = m-1;
        int col_right = n-1, col_left = 0;
        
        while(row_up<=row_down && col_left<= col_right)
        {
            for(int i = row_up;i<=col_right;i++)
            {
                ans.push_back(matrix[row_up][i]);
            }
            row_up++;
            
            if(row_up>row_down)
                break;
            
            for(int i = row_up;i<=row_down;i++)
            {
                ans.push_back(matrix[i][col_right]);
            }
            col_right--;
            
            if(col_left>col_right)
                 break;
            
            for(int i = col_right;i>=col_left;i--)
            {
                ans.push_back(matrix[row_down][i]);
            }
            row_down--;
            
            for(int i = row_down;i>=row_up;i--)
            {
                ans.push_back(matrix[i][col_left]);
            }
            col_left++;
            
        }
        return ans;  
    }
};